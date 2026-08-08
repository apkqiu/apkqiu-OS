#include <stdint.h>
#include "elf.h"
// 算……头文件吧，因为这里就只负责加载内核
bool read_sectors(uint32_t lba, uint8_t count, void *buffer);
void putstr(const char *text, const char color, const int row, const int col)
{
    char *video = (char *)0xB8000;
    for (int i = 80 * row + col, j = 0; text[j]; i++, j++)
    {
        video[i * 2] = text[j];
        video[i * 2 + 1] = color;
    }
}
// 汇编扩展
void init_temp_idt();
void halt();
void jump(void *code);
void error(const char *str)
{
    putstr(str, 0x04, 5, 0);
    halt();
}
void my_memcpy(void *dst, void *src, unsigned long long size)
{
    for (int i = 0; i < size; i++)
    {
        ((char *)dst)[i] = ((char *)src)[i];
    }
}
void my_memset(void *dst, char src, unsigned long long size)
{
    for (int i = 0; i < size; i++)
    {
        ((char *)dst)[i] = src;
    }
}
void cpuid(int leaf, int sub, unsigned int out[4]);
#define X 0xFF
unsigned int get_cr(unsigned int reg_num);
// 返回值: 0 表示成功，-1 表示传入非法编号（如 CR1）
unsigned int set_cr(unsigned int reg_num, unsigned long value);
// 主函数
void long_main()
{
    // IDT
    init_temp_idt();

    // 扩展指令集 - 满血CPU启动！
    unsigned int cpu_info[4];
    // SSE
    cpuid(0x01, 0x00, cpu_info);
    if (!(cpu_info[3] & 1 << 25))
        error("CPU has NO SSE Functions");
    unsigned int cr0 = get_cr(0);
    unsigned int cr4 = get_cr(4);
    cr0 &= ~(1 << 2);
    cr0 |= 1 << 1;
    cr4 |= 3 << 9;
    set_cr(0, cr0);
    set_cr(4, cr4);
    // AVX
    // if(!(cpu_info[2] & 1<<28)) error("CPU has NO AVX Functions");
    // unsigned int xcr = get_cr(X);
    // xcr |= 0b01110111;
    // set_cr(X, xcr);

    // 内核加载
    char *elf_addr = (char *)0x300000;
    read_sectors(64, 100, elf_addr);
    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)elf_addr; // 指针……无所谓了
    if (ehdr->e_ident[0] != ELFMAG0)
        error("ELF header mismatch");
    if (ehdr->e_ident[1] != ELFMAG1)
        error("ELF header mismatch");
    if (ehdr->e_ident[2] != ELFMAG2)
        error("ELF header mismatch");
    if (ehdr->e_ident[3] != ELFMAG3)
        error("ELF header mismatch");
    uint32_t max_offset = 0;
    Elf64_Phdr *phdr = (Elf64_Phdr *)(elf_addr + ehdr->e_phoff);
    for (int i = 0; i < ehdr->e_phnum; i++)
    {
        if (phdr[i].p_type == PT_LOAD)
        {
            uint32_t end = phdr[i].p_offset + phdr[i].p_filesz;
            if (end > max_offset)
                max_offset = end;
        }
    }
    uint32_t total_sectors = (max_offset + 511) / 512;
    for (uint32_t i=100;i<total_sectors;i++){
        read_sectors(64+i, 1, elf_addr+(i*512));
    }


    for (int i = 0; i < ehdr->e_phnum; i++)
    {
        if (phdr->p_type == PT_LOAD)
        {
            void *dst = (void *)(uintptr_t)phdr->p_paddr;
            void *src = (void *)(elf_addr + phdr->p_offset);
            if (phdr->p_filesz > 0)
            {
                my_memcpy(dst, src, phdr->p_filesz);
            }
            if (phdr->p_filesz < phdr->p_memsz)
            {
                my_memset(dst + phdr->p_filesz, 0,
                          phdr->p_memsz - phdr->p_filesz);
            }
        }
        phdr++;
    }
    void (*entry)(void) = (void (*)(void))(uintptr_t)ehdr->e_entry;
    entry();
    halt();
}