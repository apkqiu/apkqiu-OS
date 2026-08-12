// memory_probe.h
#ifndef MEMORY_PROBE_H
#define MEMORY_PROBE_H

#include <stdint.h>

// E820 地址范围描述符（20 字节，与 BIOS 返回格式一致）
typedef struct e820_entry_t{
    uint64_t base;      // 基址
    uint64_t length;    // 长度
    uint32_t type;      // 1=可用内存，2=保留，3=ACPI回收，4=ACPI NVS
} __attribute__((packed)) E820Entry;

// 内存探测信息结构（位于物理地址 0x8000）
typedef struct memory_info_t{
    uint32_t signature;     // "PMEM" 或 "ERR "
    uint8_t  version;       // 固定为 1
    uint8_t  region_count;  // E820 区域数量（若 E820 成功）
    uint16_t reserved;      // 保留，0
    uint32_t total_kb;      // 总内存大小（KB）
    E820Entry entries[]; // 紧接着是 region_count 个 e820_entry_t 描述符
} __attribute__((packed)) MemoryInfo;

// 物理地址常量
#define MEMINFO_PHYS_ADDR 0x8000

#endif