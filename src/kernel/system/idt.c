#include "system/idt.h"
#include <stdbool.h>
#include "kernelio.h"
#include <stddef.h>
#define INT_QUEUE_SIZE 256

// x86-64 IDT 条目：16 字节对齐
struct idt_entry
{
    uint16_t base_low;  // 处理函数偏移 0-15
    uint16_t selector;  // 代码段选择子（通常是 0x08 或 0x10）
    uint8_t ist;        // 中断栈表（0 表示不用 IST，使用当前栈）
    uint8_t flags;      // 类型属性（P, DPL, 中断门/陷阱门）
    uint16_t base_mid;  // 处理函数偏移 16-31
    uint32_t base_high; // 处理函数偏移 32-63
    uint32_t reserved;  // 必须为 0
} __attribute__((packed));

// IDTR 寄存器结构
struct idt_ptr
{
    uint16_t limit;
    uint64_t base;
} __attribute__((packed));

// 全局 IDT 表（最大 256 个中断）
static struct idt_entry idt[256] __attribute__((aligned(16)));

static struct idt_ptr idtr;
volatile IntEvent interrupt_queue_buf[INT_QUEUE_SIZE];
Queue interrupt_queue;
void init_queue()
{
    queue_init(&interrupt_queue, &interrupt_queue_buf, INT_QUEUE_SIZE, sizeof(IntEvent));
}
void idt_set_gate(int num, uint64_t handler, uint16_t selector, uint8_t flags)
{
    idt[num].base_low = (uint16_t)(handler & 0xFFFF);
    idt[num].base_mid = (uint16_t)((handler >> 16) & 0xFFFF);
    idt[num].base_high = (uint32_t)((handler >> 32) & 0xFFFFFFFF);
    idt[num].selector = selector; // ← 这一行必须存在
    idt[num].ist = 0;             // 中断栈表，通常设为0
    idt[num].flags = flags;       // 例如 0x8E
    idt[num].reserved = 0;
}

static inline bool vector_has_error_code(uint8_t vec)
{
    // 标准 x86-64 有错误码的向量列表
    return (vec == 8) || (vec == 10) || (vec == 11) ||
           (vec == 12) || (vec == 13) || (vec == 14) ||
           (vec == 17) || (vec == 30);
}
void make_idt();
void init_idt()
{
    init_queue();
    // 1. 循环填充所有 256 个表项
    make_idt();

    // 3. 重映射 PIC（8259）
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);

    // ⚠️ 关键：只开键盘（IRQ1），屏蔽定时器（IRQ0）和从片
    outb(0x21, 0x00); // 1111 1101, 只开 IRQ1
    outb(0xA1, 0x00); // 全关从片

    // 5. 加载 IDTR
    idtr.limit = sizeof(idt) - 1;
    idtr.base = (uint64_t)idt;
    __asm__ volatile("lidt %0" : : "m"(idtr));

    // 6. 开启可屏蔽中断（相当于 CPU 的 "STI" 指令）
    __asm__ volatile("sti");
}
void common_handler(int vector, IntFrame *frame, uint64_t error_code)
{
    uint64_t data = 0;
    if (vector == 0x21)
    {
        data = inb(0x60);
    }

    // EOI
    if (vector >= 0x20 && vector <= 0x27)
    {
        // 主 PIC 中断
        outb(0x20, 0x20);
    }
    else if (vector >= 0x28 && vector <= 0x2F)
    {
        // 从 PIC 中断（必须先发从片，再发主片）
        outb(0xA0, 0x20);
        outb(0x20, 0x20);
    }
    // 其他向量（CPU 异常或软件中断）不发送 EOI
    IntEvent e = {vector, frame->rflags, error_code, data};
    queue_enqueue(&interrupt_queue, &e);
}

#include "system/idth.h"