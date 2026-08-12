OUTPUT_FORMAT(elf64-x86-64)
ENTRY(kernel_main)    /* 你的入口函数名 */
PHDRS
{
    text PT_LOAD FLAGS(5);   /* 5 = 可读(4) + 可执行(1) => R E */
    rodata PT_LOAD FLAGS(4); /* 4 = 只读 R */
    data PT_LOAD FLAGS(6);   /* 6 = 可读(4) + 可写(2) => RW */
}

SECTIONS {
    . = 0xFFFF800000100000;           /* 内核加载地址（必须被页表映射） */
    .text : {
        *(.text)
        *(.text.*)
    } :text
    .rodata : { 
        *(.rodata)
        *(.rodata.*)
    } :rodata
    .data : {
        *(.data) 
        *(.data.*)
        *(.data.rel.ro*)
    } :data
    .bss : {
        *(.bss)
        *(.bss.*)
        *(COMMON)
    } :data
    .eh_frame : {
        *(.eh_frame)
    } :rodata
}