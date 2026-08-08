; boot.asm - 主引导程序（调整为 64 扇区）
[org 0x0000]
[bits 16]

%include "include/common.inc"

_start:
    ; 复制自身到 BOOT_BASE
    mov ax, INIT_SEG
    mov ds, ax
    xor si, si

    mov ax, BOOT_SEG
    mov es, ax
    xor di, di

    mov cx, 256
    cld
    rep movsw

    jmp BOOT_SEG:.copied

.copied:
    mov ax, BOOT_SEG
    mov ds, ax
    mov es, ax

    mov ax, 0x1000
    mov ss, ax
    mov sp, 0x0000

    mov [BOOT_DRIVE_ID], dl

    ; 从第2扇区开始读取 63 个扇区（即总共 64 个扇区，包含引导扇区本身）
    ; 但为了简化，我们只读取接下来的 63 个扇区，加上引导扇区共 64 个。
    mov dl, [BOOT_DRIVE_ID]
    mov dh, 0
    mov ch, 0
    mov cl, 2
    mov ah, 0x02
    mov al, 63          ; 读取 63 个扇区（扇区 1~63，0 是引导扇区）
    mov bx, BOOT_SEG
    mov es, bx
    mov bx, 0x0200
    int 0x13
    jc give_up
    jmp loaded


give_up:
    mov si, MSG_ERROR
    call print_string
    cli
    hlt

%include "real/real_mode.inc"
BOOT_DRIVE_ID: db 0x00

MSG_ERROR:           db "An Error Occoured.", 0x0D, 0x0A, 0

times 510 - ($ - $$) db 0
dw 0xAA55 ;引导扇区止


loaded:
    call probe_memory
    
    call enable_a20
    lgdt [gdt.pointer]

    cli
    mov eax, cr0
    or  al, 1
    mov cr0, eax
    jmp dword 0x08:(protected_start + BOOT_BASE)



; 实模式模块
%include "real/a20.inc"
%include "real/probe_memory.inc"
%include "protected/gdt.inc"
%include "protected/protected_mode.inc"

protected64_start:
    jmp 0x00006200