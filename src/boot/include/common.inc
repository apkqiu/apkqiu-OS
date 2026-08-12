; include/common.inc
%ifndef __COMMON_INC__
%define __COMMON_INC__

; 固定地址常量
BOOT_BASE       equ 0x20000
INIT_SEG        equ 0x07C0
BOOT_SEG        equ 0x2000
BOOT_SEG2       equ 0x2800

; 页表基址
PAGE_TABLE_BASE equ 0x10000
PML4_BASE       equ PAGE_TABLE_BASE
PDP_LOW_BASE equ PAGE_TABLE_BASE + (pdpt_low - pml4_table)
PDP_HIGH_BASE equ PAGE_TABLE_BASE + (pdpt_high - pml4_table)
PD_BASE         equ PDP_LOW_BASE  + 0x1000
PT0_BASE        equ PD_BASE   + 0x1000
PT1_BASE        equ PT0_BASE  + 0x1000

; 段选择子（与 GDT 对应）
KERNEL_CS       equ 0x18       ; 64位代码段

; 内核加载地址（长模式读取后续扇区后存放）
KERNEL_LOAD_ADDR equ 0x100000
%endif