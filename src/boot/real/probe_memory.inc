; ================================================================
; probe_memory.inc
; 功能：探测系统内存，将结果写入 0x8000 处（安全地址）
; 数据格式（从 0x8000 开始）：
;   偏移 0-3  ：签名 "PMEM"（成功）或 "ERR "（失败）
;   偏移 4    ：版本号（固定 1）
;   偏移 5    ：E820 区域数量（若 E820 成功）；失败时为 0
;   偏移 6-7  ：保留（0）
;   偏移 8-11 ：总内存大小（单位 KB，32 位）
;   偏移 12   ：开始存放 N 个 E820 地址范围描述符（每个 20 字节）
;
; 调用：call probe_memory
; 返回：CF=0 成功，CF=1 失败（所有方法均失败）
; 破坏：无（保护所有寄存器）
; ================================================================

[bits 16]

probe_memory:
    ; 手动保存所有可能被修改的寄存器（顺序无所谓，只要弹出时逆序即可）
    push ax
    push bx
    push cx
    push dx
    push si
    push di
    push es
    push ds

    ; ---------- 设置 ES = 0x0800，目标段（物理地址 0x8000） ----------
    mov ax, 0x0800
    mov es, ax
    xor di, di                ; ES:DI = 0x0800:0000

    ; ---------- 写入初始签名 "PMEM" ----------
    mov eax, 'PMEM'
    stosd                     ; 写入 4 字节签名
    mov byte [es:di], 1       ; 版本 = 1
    inc di
    mov byte [es:di], 0       ; 区域数量暂写 0
    inc di
    mov word [es:di], 0       ; 保留
    add di, 2
    mov dword [es:di], 0      ; 总内存暂写 0
    add di, 4

    ; 现在 DI 指向描述符区起始（偏移 0x0C）

    ; ---------- 方法 3：E820 探测 ----------
    xor ebx, ebx              ; 起始计数
    mov si, 0                 ; 区域计数器
    push di                   ; 保存描述符起始偏移（因为后续会修改 DI，需额外保存）

.e820_loop:
    mov eax, 0xE820
    mov ecx, 20
    mov edx, 0x534D4150       ; 'SMAP'
    int 0x15
    jc .e820_done
    cmp eax, 0x534D4150
    jne .e820_done

    inc si                    ; 有效区域 +1
    add di, 20                ; 指向下一个描述符位置
    cmp ebx, 0
    jne .e820_loop

.e820_done:
    test si, si
    jz .fallback_e801         ; 若没有区域则回退

    ; ---------- E820 成功 ----------
    ; 写入区域数量
    mov ax, si
    mov byte [es:5], al       ; 偏移 5

    ; 计算总内存（累加所有 Type=1 的区域长度，转换为 KB）
    pop di                    ; 恢复描述符起始偏移
    push di                   ; 重新压入以便后续弹出平衡（但下面不再需要，可以在最后统一 pop）
    ; 但更规范：pop 后不再 push，下面直接使用 di
    ; 我们重写：pop di 得到起始偏移，然后直接使用
    ; 但还要保护 di 不被破坏，我们下面用 bx 做循环计数器

    mov cx, si                ; 区域数
    xor bx, bx                ; 循环计数器
    xor eax, eax              ; 总字节数低 32 位

.sum_loop:
    cmp bx, cx
    jge .sum_done
    cmp byte [es:di+16], 1    ; 类型 = 1（可用内存）
    jne .skip
    add eax, [es:di+8]        ; 长度低 32 位
    ; 忽略高 32 位（一般 PC 内存 < 4GB）
.skip:
    add di, 20
    inc bx
    jmp .sum_loop

.sum_done:
    shr eax, 10               ; 字节 → KB（除以 1024）
    mov [es:8], eax           ; 写入偏移 8
    clc
    jmp .exit

    ; ---------- 回退方法 2：INT 0x15 AX=E801 ----------
.fallback_e801:
    ; 将签名改为 "ERR "，表示 E820 失败，但可能 E801 成功
    ; 重新定位到开头写入签名
    mov di, 0
    mov eax, 'ERR '
    stosd

    mov ax, 0xE801
    int 0x15
    jc .fallback_int12

    ; E801 成功：AX = 低端 KB，BX = 高端 64KB 块数
    movzx ecx, ax             ; 低端 KB（16 位扩展到 32 位）
    movzx eax, bx             ; 块数
    shl eax, 6                ; 块数 × 64 = KB
    add eax, ecx              ; 总 KB
    mov [es:8], eax
    mov byte [es:5], 0        ; 区域数量为 0（表示非 E820）
    clc
    jmp .exit

    ; ---------- 回退方法 1：INT 0x12 ----------
.fallback_int12:
    int 0x12                  ; 返回 AX = KB
    mov [es:8], ax
    mov byte [es:5], 0
    clc
    jmp .exit

.exit:
    ; 清理：如果 E820 成功，之前 push di 已被 pop 掉，现在栈平衡
    ; 但我们在进入 .exit 前没有多余的 push，所以直接恢复所有保存的寄存器
    ; 注意弹出顺序与压入相反
    pop di
    pop ds
    pop es
    pop di
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret