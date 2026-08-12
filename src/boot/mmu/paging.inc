%ifndef __PAGING_INC__
%define __PAGING_INC__
%include "include/common.inc"

align 4096
pml4_table:
    ; PML4[0]：恒等映射（临时），指向低地址 PDP
    dq (PDP_LOW_BASE | 0x03)
    ; PML4[256]：高地址映射，指向高地址 PDP
    dq (PDP_HIGH_BASE | 0x03)
    times 510 dq 0

align 4096
pdpt_low:                 ; 低地址 PDP（用于恒等映射）
    dq (0 | 0x83)          ; 1GB 大页，物理 0~1GB -> 虚拟 0~1GB
    times 511 dq 0

align 4096
pdpt_high:                ; 高地址 PDP
    dq (0 | 0x83)          ; 物理 0~1GB -> 虚拟 0xFFFF800000000000
    dq (0x40000000 | 0x83) ; 物理 1~2GB -> 虚拟 0xFFFF800040000000
    times 510 dq 0

pml4_end:

%endif