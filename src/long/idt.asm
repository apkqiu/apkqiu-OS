[bits 64]
KERNEL_CS       equ 0x18       ; 64位代码段

BOOT_BASE       equ 0x20000
IDT_ENTRIES   equ 256
IDT_ENTRY_SIZE equ 16

align 16
idt:
    times IDT_ENTRIES * IDT_ENTRY_SIZE db 0

idtr:
    dw IDT_ENTRIES * IDT_ENTRY_SIZE - 1
    dq idt + BOOT_BASE

exception_handler:
    cli
    hlt

ignore_handler:
    iretq

global init_temp_idt
init_temp_idt:
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi

    mov rsi, ignore_handler
    mov rdx, KERNEL_CS
    mov bl,  0x8E
    mov rcx, IDT_ENTRIES
    mov rdi, idt + BOOT_BASE
.fill_all:
    call set_one_entry
    add rdi, IDT_ENTRY_SIZE
    loop .fill_all

    mov rsi, exception_handler
    mov rdx, KERNEL_CS
    mov bl,  0x8E
    mov rcx, 32
    mov rdi, idt + BOOT_BASE
.fill_exc:
    call set_one_entry
    add rdi, IDT_ENTRY_SIZE
    loop .fill_exc

    lidt [abs idtr + BOOT_BASE]

    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret

set_one_entry:
    mov ax, si
    mov [rdi], ax
    mov [rdi + 2], dx
    mov byte [rdi + 4], 0
    mov [rdi + 5], bl
    mov rax, rsi
    shr rax, 16
    mov [rdi + 6], ax
    shr rax, 16
    mov [rdi + 8], eax
    mov dword [rdi + 12], 0
    ret