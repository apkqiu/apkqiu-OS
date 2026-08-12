[bits 64]
KERNEL_CS       equ 0x18

; ---------- 数据段 ----------
align 16
idt:
    times 256 * 16 db 0          ; 4KB IDT表

idtr:
    dw 256 * 16 - 1              ; 表长度
    dq idt                       ; 直接使用标签，勿再加 BOOT_BASE

; ---------- 处理函数 ----------
exception_handler:
    cli
    hlt

ignore_handler:
    iretq

; ---------- 初始化函数 ----------
global init_temp_idt
init_temp_idt:
    ; 保存用到的寄存器（若确定调用者不依赖它们，可省略以进一步缩小）
    push rax
    push rbx
    push rcx
    push rdx
    push rsi
    push rdi

    cli                          ; 加载前关中断，防止意外

    mov rdi, idt                 ; RDI = IDT表基址
    mov rcx, 256                 ; 循环计数器（256 -> 1，正好对应索引 0~255）
    mov rdx, KERNEL_CS           ; 段选择子
    mov bl, 0x8E                 ; 属性：P=1, DPL=00, 中断门类型=0xE

.loop:
    ; ----- 判断索引（前32个用 exception_handler，其余用 ignore_handler）-----
    ; 当 rcx = 256~225 时，对应索引 0~31，属于异常
    cmp rcx, 224
    jg  .exc_handler
    mov rsi, ignore_handler
    jmp .write_entry
.exc_handler:
    mov rsi, exception_handler
.write_entry:

    ; ----- 内联构造 64 位中断门（16 字节），避免 call/ret 开销 -----
    mov rax, rsi                ; 处理函数地址

    ; 1. 偏移低 16 位 (byte 0-1)
    mov [rdi], ax

    ; 2. 段选择子 (byte 2-3)
    mov [rdi + 2], dx

    ; 3. IST 和保留位 (byte 4)
    mov byte [rdi + 4], 0

    ; 4. 门属性 (byte 5)
    mov [rdi + 5], bl

    ; 5. 偏移中间 16 位 (byte 6-7)
    shr rax, 16
    mov [rdi + 6], ax

    ; 6. 偏移高 32 位 (byte 8-11)
    shr rax, 16
    mov [rdi + 8], eax

    ; 7. 保留位清零 (byte 12-15)
    mov dword [rdi + 12], 0
    ; ---------------------------------------------

    add rdi, 16                 ; 指向下一个描述符
    dec rcx
    jnz .loop

    ; 加载 IDT（使用 RIP 相对寻址，更稳妥）
    lidt [rel idtr]

    pop rdi
    pop rsi
    pop rdx
    pop rcx
    pop rbx
    pop rax
    ret