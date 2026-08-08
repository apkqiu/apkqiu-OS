%ifndef __PROTECTED_MODE_INC__
%define __PROTECTED_MODE_INC__
%include "include/common.inc"
%include "mmu/paging.inc"       ; 引用页表符号
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

    mov eax, cr4
    or eax, (1 << 5)
    mov cr4, eax

    mov ecx, 0xC0000080
    rdmsr
    or eax, (1 << 8)
    wrmsr

    mov eax, PML4_BASE
    mov cr3, eax

    mov eax, cr0
    or eax, (1 << 31)
    mov cr0, eax

    jmp 0x18:(protected64_start + BOOT_BASE)

    jmp protected_give_up


print_protected:
    pushad
    mov edi, 0xB8000
    mov edx, [BUFFER_OFFSET + BOOT_BASE]
    lea edi, [edi + edx*2]
    add edx, 80
    cmp edx, 80*25
    jne .write_back
    xor edx, edx
.write_back:
    mov [BUFFER_OFFSET + BOOT_BASE], edx
    mov ah, al
.loop:
    lodsb
    test al, al
    jz .done
    stosw
    jmp .loop
.done:
    popad
    ret

protected_give_up:
    mov esi, P32MSG_ERROR
    add esi, BOOT_BASE
    mov al, 0x07
    call print_protected
    cli
    hlt


; 32位本地消息
P32MSG_ERROR:          db "An 32-bit Error Occoured.", 0

%endif