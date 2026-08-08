[section .text.start]
[global _start]
[extern long_main]
_start:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    mov rsp, 0x60000
    ;sse
    mov rax, cr4
    or rax, 0x600
    mov cr4, rax

    call long_main
.lp:
    cli
    hlt
    jmp .lp