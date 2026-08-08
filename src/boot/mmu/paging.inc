%ifndef __PAGING_INC__
%define __PAGING_INC__
%include "include/common.inc"

align 4096
pml4_table:
    dq (PDP_BASE | 0x03)
    times 511 dq 0

align 4096
pdpt_table:
    dq (PD_BASE | 0x03)
    times 511 dq 0

align 4096
pd_table:
    dq (PT0_BASE | 0x03)
    dq (PT1_BASE | 0x03)
    times 510 dq 0

align 4096
pt0_table:
    %assign i 0
    %rep 512
        dq (i * 0x1000 | 0x03)
        %assign i i+1
    %endrep

align 4096
pt1_table:
    %assign i 0
    %rep 512
        dq ((512 + i) * 0x1000 | 0x03)
        %assign i i+1
    %endrep

pml4_end:

%endif