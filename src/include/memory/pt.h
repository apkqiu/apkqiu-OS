// include/mm/vmm_pt.h
#pragma once
#include <stdint.h>
#include <stdbool.h>

// 页表项（64位）
typedef struct PTE {
    union {
        uint64_t raw;
        struct {
            uint64_t present     : 1;  // 0: 是否在内存中
            uint64_t writable    : 1;  // 1: 是否可写
            uint64_t user_access : 1;  // 2: 用户态是否可访问
            uint64_t write_through:1;  // 3: 写透缓存
            uint64_t cache_disable:1;  // 4: 禁用缓存
            uint64_t accessed    : 1;  // 5: 是否被访问过
            uint64_t dirty       : 1;  // 6: 是否被写过
            uint64_t huge_page   : 1;  // 7: 是否为巨页（PD 级）
            uint64_t global      : 1;  // 8: 全局页（不刷新 TLB）
            uint64_t available   : 3;  // 9-11: 软件可用
            uint64_t phys_addr   : 40; // 12-51: 物理地址（高40位）
            uint64_t available2  : 11; // 52-62: 软件可用
            uint64_t no_execute  : 1;  // 63: NX 位
        };
    };
} PTE;

// 各级页表（每个都是 512 项的数组）
typedef struct {
    PTE entries[512];
} PML4, PDPT, PD, PT;