// gdt.hpp
#pragma once
#include <stdint.h>

// 64位 GDT 描述符 (8字节)
struct GDTEntry {
    uint16_t limit_low;    // 段限长 0-15位
    uint16_t base_low;     // 基址 0-15位
    uint8_t  base_mid;     // 基址 16-23位
    uint8_t  access;       // 访问权限字节 (P, DPL, S, E, ED/C, RW, A)
    uint8_t  granularity;  // 粒度 (G, DB, L, AVL, 段限长 16-19位)
    uint8_t  base_high;    // 基址 24-31位
} __attribute__((packed));

// GDTR 寄存器结构 (6字节，但基址在64位下是8字节，所以总大小10字节)
struct GDTR {
    uint16_t limit;        // 总大小 - 1
    uint64_t base;         // GDT 线性地址
} __attribute__((packed));

// gdt_constants.hpp
#define GDT_ACCESS_PRESENT       0x80  // 段存在
#define GDT_ACCESS_DPL0          0x00  // 内核级 (0)
#define GDT_ACCESS_DPL3          0x60  // 用户级 (3)
#define GDT_ACCESS_SYSTEM        0x10  // 1=代码/数据段, 0=系统段
#define GDT_ACCESS_EXECUTABLE    0x08  // 1=代码段, 0=数据段
#define GDT_ACCESS_DIR_CONFORM   0x04  // 代码: 依从, 数据: 方向
#define GDT_ACCESS_READ_WRITE    0x02  // 代码: 可读, 数据: 可写
#define GDT_ACCESS_ACCESSED      0x01  // 访问位 (通常置0)

#define GDT_GRAN_PAGE            0x80  // 4KB 页粒度 (否则字节粒度)
#define GDT_GRAN_64BIT           0x20  // L=1 (64位代码段)
#define GDT_GRAN_32BIT           0x40  // D/B=1 (32位代码/栈)
#define GDT_GRAN_LIMIT_HIGH      0x0F  // 限长高4位