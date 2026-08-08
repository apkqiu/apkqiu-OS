%ifndef __GDT_INC__
%define __GDT_INC__
%include "include/common.inc"
[bits 16]

gdt:
.start:
    dd 0x00000000
    dd 0x00000000
.code32:                ; 选择子 0x08
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 0x9A
    db 0xCF
    db 0x00
.data:                  ; 选择子 0x10
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 0x92
    db 0xCF
    db 0x00
.code64:                ; 选择子 0x18
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 0x9A
    db 0xAF
    db 0x00
.end:
.pointer:
    dw .end - .start - 1
    dd .start + BOOT_BASE

%endif