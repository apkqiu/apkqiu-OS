%ifndef __A20_INC__
%define __A20_INC__
[bits 16]

enable_a20:
    push si
    push ax
    cli
    call a20_wait
    mov al, 0xAD
    out 0x64, al
    call a20_wait
    mov al, 0xD0
    out 0x64, al
    call a20_wait2
    in  al, 0x60
    push ax
    call a20_wait
    mov al, 0xD1
    out 0x64, al
    call a20_wait
    pop ax
    or  al, 0x02
    out 0x60, al
    call a20_wait
    mov al, 0xAE
    out 0x64, al
    sti
    pop ax
    pop si
    ret

a20_wait:
    in  al, 0x64
    test al, 0x02
    jnz a20_wait
    ret

a20_wait2:
    in  al, 0x64
    test al, 0x01
    jz  a20_wait2
    ret

%endif