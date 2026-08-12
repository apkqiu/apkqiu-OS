#include <stdint.h>
#include "elf.h"
// 算……头文件吧，因为这里就只负责加载内核
bool read_sectors(uint32_t lba, uint8_t count, void *buffer);
static inline void putstr(const char *text, const char color, const int row, const int col)
{
    char *video = (char *)0xB8000;
    for (int i = 80 * row + col, j = 0; text[j]; i++, j++)
    {
        video[i * 2] = text[j];
        video[i * 2 + 1] = color;
    }
}
#define error(str) do{\
    putstr(str, 0x04, 5, 0);\
    goto exit;\
}while(0)
static inline void my_memcpy(void *dst, void *src, unsigned long long size)
{
    for (int i = 0; i < size; i++)
    {
        ((char *)dst)[i] = ((char *)src)[i];
    }
}
static inline void my_memset(void *dst, char src, unsigned long long size)
{
    for (int i = 0; i < size; i++)
    {
        ((char *)dst)[i] = src;
    }
}
#define KS 0xFFFF800000000000ULL
void load_kernel() {
    // 1. 读取 ELF 头（假设前 1 个扇区足够容纳头 + 程序头，但为了安全，读 4 个扇区）
    uint8_t elf_hdr_buf[2048];       // 4 个扇区，足够存放 ELF 头和程序头表
    read_sectors(64, 4, elf_hdr_buf); // 根据你的实际 LBA 起始调整（原来是 64）

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)elf_hdr_buf;
    if (ehdr->e_ident[0] != ELFMAG0 || ehdr->e_ident[1] != ELFMAG1 ||
        ehdr->e_ident[2] != ELFMAG2 || ehdr->e_ident[3] != ELFMAG3)
        error("ELF header mismatch");

    // 2. 解析程序头表
    Elf64_Phdr *phdr = (Elf64_Phdr *)(elf_hdr_buf + ehdr->e_phoff);
    uint16_t phnum = ehdr->e_phnum;

    // 3. 遍历每个 LOAD 段，直接从磁盘读取到目标虚拟地址
    for (int i = 0; i < phnum; i++) {
        if (phdr[i].p_type != PT_LOAD) continue;

        uint64_t file_offset = phdr[i].p_offset;    // 段在文件中的偏移
        uint64_t file_size   = phdr[i].p_filesz;     // 段在文件中的大小
        uint64_t mem_size    = phdr[i].p_memsz;      // 段在内存中的大小
        void *dst = (void *)(uintptr_t)phdr[i].p_vaddr;  // 目标虚拟地址（高地址）

        // 计算段在磁盘上的起始 LBA（假设磁盘扇区大小为 512）
        uint32_t start_lba = 64 + (file_offset / 512);
        uint32_t offset_in_sector = file_offset % 512;

        // 如果段不在扇区边界上，需要处理未对齐部分，但通常文件偏移和扇区对齐
        // 简单起见，我们假设段开始于扇区边界（或我们使用逐字节读取，但更复杂）
        // 这里我们采用逐扇区复制到目标地址，若偏移不对齐则先读一个扇区到临时缓冲再复制。
        if (offset_in_sector != 0) {
            // 先读取第一个不完整的扇区
            uint8_t tmp_sector[512];
            read_sectors(start_lba, 1, tmp_sector);
            uint32_t copy_bytes = (file_size < (512 - offset_in_sector)) ? file_size : (512 - offset_in_sector);
            my_memcpy(dst, tmp_sector + offset_in_sector, copy_bytes);
            file_size -= copy_bytes;
            dst += copy_bytes;
            start_lba++;
        }

        // 然后整扇区复制
        while (file_size >= 512) {
            uint32_t sectors = file_size / 512;
            // 为了避免一次读太多扇区，可以分批次，但这里直接一次性读（注意缓冲区）
            // 我们直接读入目标地址，因为目标地址是虚拟地址，页表已映射，可以直接写
            read_sectors(start_lba, sectors, dst);
            dst += sectors * 512;
            file_size -= sectors * 512;
            start_lba += sectors;
        }

        // 剩余不足一个扇区的部分
        if (file_size > 0) {
            uint8_t tmp_sector[512];
            read_sectors(start_lba, 1, tmp_sector);
            my_memcpy(dst, tmp_sector, file_size);
        }

        // 清零 BSS 部分（如果 mem_size > file_size）
        if (mem_size > phdr[i].p_filesz) {
            my_memset(dst + phdr[i].p_filesz, 0, mem_size - phdr[i].p_filesz);
        }
    }

    // 4. 跳转到入口（高地址）
    void (*entry)(void) = (void (*)(void))ehdr->e_entry;
    entry();

exit:
    return;
}
