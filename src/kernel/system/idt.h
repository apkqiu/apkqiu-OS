#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "../std/queue.h"

// x86-64 中断栈帧（由 CPU 硬件自动压入）
// 注意：压入顺序是  SS, RSP, RFLAGS, CS, RIP（由高地址向低地址增长）
typedef struct IntFrame
{
    uint64_t rip;    // 返回地址（触发中断时的指令指针）
    uint64_t cs;     // 代码段选择子
    uint64_t rflags; // 标志寄存器（包含 IF 位等）
    uint64_t rsp;    // 触发中断时的栈指针（⚠️ 仅在特权级变化时有效，内核态触发时不存在）
    uint64_t ss;     // 堆栈段选择子（⚠️ 同理，仅特权级变化时有效）
} __attribute__((packed)) IntFrame;

typedef struct IntEvent
{
    uint32_t vector; // 中断向量号（如 0x21=键盘，0x0E=缺页）
    uint64_t cpu_rflags;
    uint32_t error; // CPU 压入的错误码（无错误码的中断填 0）
    uint64_t data;
} IntEvent;

extern Queue interrupt_queue;

void init_idt();