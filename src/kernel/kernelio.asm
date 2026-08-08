[bits 64]
[section .text]

[global inb]
[global outb]
[global inw]
[global outw]
[global halt]
; uint8_t inb(uint16_t port)
; 参数: edi (port)
; 返回: al
inb:
    mov dx, di      ; 端口号 16 位放入 DX
    in  al, dx
    ret

; void outb(uint16_t port, uint8_t val)
; 参数: edi (port), esi (val)
outb:
    mov dx, di
    mov al, sil
    out dx, al
    ret

; uint16_t inw(uint16_t port)
; 参数: edi (port)
; 返回: ax
inw:
    mov dx, di
    in  ax, dx
    ret

; void outw(uint16_t port, uint16_t val)
; 参数: edi (port), esi (val)
outw:
    mov dx, di
    mov ax, si
    out dx, ax
    ret

halt:

    hlt
    jmp halt

