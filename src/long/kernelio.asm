[bits 64]
[section .text]

[global inb]
[global outb]
[global inw]
[global outw]
[global halt]
[global jump]
[global cpuid]
[global get_cr]
[global set_cr]
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
    cli
    hlt

jump:
    jmp rdi

cpuid:
    push rbx
    mov eax, edi
    mov ecx, esi
    mov rdi, rdx
    cpuid
    mov [rdi], eax
    mov [rdi+4], ebx
    mov [rdi+8], ecx
    mov [rdi+12], edx
    pop rbx
    ret

X equ 0xFF
; xcr0
get_cr:
    cmp edi, 0
    je .cr0
    cmp edi, 2
    je .cr2
    cmp edi, 3
    je .cr3
    cmp edi, 4
    je .cr4
    cmp edi, 8
    je .cr8
    cmp edi, X
    je .xcr
    ; 非法参数，返回 -1
    mov rax, -1
    ret
.cr0:
    mov rax, cr0
    ret
.cr2:
    mov rax, cr2
    ret
.cr3:
    mov rax, cr3
    ret
.cr4:
    mov rax, cr4
    ret
.cr8:
    mov rax, cr8
    ret
.xcr:
    xor rcx, rcx
    xgetbv
    ret


set_cr:
    ; 1. 检查寄存器编号是否合法 (0,2,3,4 有效，1 无效)
    cmp edi, 0
    je .write_cr0
    cmp edi, 2
    je .write_cr2
    cmp edi, 3
    je .write_cr3
    cmp edi, 4
    je .write_cr4
    cmp edi, 8
    je .write_cr8
    cmp edi, X
    je .write_xcr
    ; 非法编号（包括 CR1），返回 -1
    mov eax, -1
    ret

.write_cr0:
    mov rax, rsi        ; 将值载入 RAX
    mov cr0, rax        ; 写入 CR0
    xor eax, eax        ; 返回 0 表示成功
    ret

.write_cr2:
    mov rax, rsi
    mov cr2, rax        ; 写入 CR2（技术上允许，但极少使用，通常只读）
    xor eax, eax
    ret

.write_cr3:
    mov rax, rsi
    mov cr3, rax        ; 写入 CR3（切换页表基址）
    xor eax, eax
    ret

.write_cr4:
    mov rax, rsi
    mov cr4, rax        ; 写入 CR4（控制各种扩展特性）
    xor eax, eax
    ret

.write_cr8:
    mov rax, rsi
    mov cr8, rax 
    xor eax, eax
    ret
.write_xcr:
    xor rcx, rcx
    mov rax, rsi
    xsetbv
    xor eax, eax
    ret