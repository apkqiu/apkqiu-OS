[section .text.start]
[bits 64]
[global _start]
[extern init_temp_idt]
[extern load_kernel]
_start:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov rsp, 0x60000

    call init_temp_idt
    call load_kernel
.lp:
    cli
    hlt
    jmp .lp