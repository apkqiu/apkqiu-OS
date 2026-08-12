OUTPUT_FORMAT(elf64-x86-64)
ENTRY(_start)    /* 你的入口函数名 */
SECTIONS {
    . = 0x24000;           /* 内核加载地址（必须被页表映射） */
    .text : {
        *(.text.start)     /* 我们自定义的段，放在最前面 */
        *(.text.*)
        *(.text)
    }
        
    .rodata : { *(.rodata) }
    .data : { *(.data) }
    .bss : {
        *(.bss)
        *(COMMON)
    }
}