%ifndef __REAL_MODE_INC__
%define __REAL_MODE_INC__
[bits 16]

print_string:
    push ax
    push bx
    push si
    mov ah, 0x0E
    mov bx, 0x0007
.loop:
    lodsb
    test al, al
    jz  .done
    int 0x10
    jmp .loop
.done:
    pop si
    pop bx
    pop ax
    ret

%endif