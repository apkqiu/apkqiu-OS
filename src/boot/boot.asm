; boot.asm - 主引导程序
[org 0x0000]
[bits 16]
_start:
    mov ax, BOOT_SEG
    mov ds, ax
    mov es, ax

    mov ax, 0x1000
    mov ss, ax
    mov sp, 0x0000

    ; 从第1扇区开始读取 64 个扇区（包含引导扇区本身）
    mov dh, 0
    mov ch, 0
    mov cl, 1
    mov ah, 0x02
    mov al, 64
    mov bx, BOOT_SEG
    mov es, bx
    mov bx, 0x0000
    int 0x13
    jc give_up
    jmp .loaded
.loaded:
    call probe_memory
.a20:
    in  al, 0x92
    or  al, 0x02
    out 0x92, al
.gdt:
    lgdt [gdt.pointer]

    cli
    mov eax, cr0
    or  al, 1
    mov cr0, eax
    jmp dword 0x08:(protected_start + BOOT_BASE)
    ; jc的话不用了，自己会往下流的
give_up:
    cli
    hlt
    jmp give_up
    
%include "real/probe_memory.inc"
%include "protected/gdt.inc"
%include "include/common.inc"
[bits 32]
protected_start:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov esp, 0x30000

    mov edi, 0xB8000
    mov ecx, 80*25
    mov ax, 0x0720
    rep stosw

    cld
    mov esi, pml4_table + BOOT_BASE
    mov edi, PAGE_TABLE_BASE
    mov ecx, (pml4_end - pml4_table) / 4
    rep movsd

    ; 修正 PML4[0]：低地址 PDP 表
    mov eax, PAGE_TABLE_BASE + (pdpt_low - pml4_table)   ; 低 PDP 物理地址
    mov [PAGE_TABLE_BASE], eax
    or dword [PAGE_TABLE_BASE], 0x03

    ; 修正 PML4[256]：高地址 PDP 表
    mov eax, PAGE_TABLE_BASE + (pdpt_high - pml4_table)  ; 高 PDP 物理地址
    mov [PAGE_TABLE_BASE + 8*256], eax
    or dword [PAGE_TABLE_BASE + 8*256], 0x03

    mov eax, cr4
    or eax, (1 << 5) | (3 << 9)
    mov cr4, eax

    mov ecx, 0xC0000080
    rdmsr
    or eax, (1 << 8)
    wrmsr

    mov eax, PML4_BASE
    mov cr3, eax

    mov eax, cr0
    and ax, 0xFFFB
    or eax, (1 << 31) | (1 << 1)
    mov cr0, eax

    jmp 0x18:(long_start + BOOT_BASE)

    jmp give_up
times 510 - ($ - $$) db 0x00
dw 0xAA55 ;引导扇区止

%include "mmu/paging.inc"       ; 引用页表符号

align 512
long_start:



