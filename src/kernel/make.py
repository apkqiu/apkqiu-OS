from builder import *
from consts import *

d = MakeConfig()


def gxx_elf(dst, src):
    execute(
        X86_64.CXX,
        X86_64.CFLAGS,
        "-O2",
        *src,
        "-o",
        dst,
    )


def gcc_elf(dst, src):
    execute(
        X86_64.CC,
        X86_64.CFLAGS,
        "-mcmodel=large",
        "-fno-pic",
        "-O2",
        *src,
        "-o",
        dst,
    )


def gcc_nosse(dst, src):
    execute(
        X86_64.CC,
        X86_64.CFLAGS,
        "-mcmodel=large",
        "-O2",
        (
            "-mgeneral-regs-only",
            "-mno-mmx",
            "-mno-sse",
            "-mno-sse2",
            "-mno-sse3",
            "-mno-sse4",
            "-mno-avx",
            "-mno-avx2",
            "-mno-avx512f",
        ),
        *src,
        "-o",
        dst,
    )


def nasm_elf(dst, src):
    execute("nasm", "-f", "elf64", *src, "-o", dst)


def ld_link(dst, src, ldfile):
    execute(X86_64.LD, "-T", ldfile, "-o", dst, *src)


ERROR_CODE_VECTORS = {8, 10, 11, 12, 13, 14, 17, 30}


@d.register("src/include/system/idth.h", [])
def make_idth(dst, src):
    with open(dst, "w") as f:
        f.write(
            """#pragma once
// PyMake Auto Generated

#include "idt.h"
void idt_set_gate(int num, uint64_t handler, uint16_t selector, uint8_t flags);
void common_handler(int vector, IntFrame *frame, uint64_t error_code);
"""
        )
        f.writelines(
            f"__attribute__((interrupt)) void idt_{i}(IntFrame *frame){{common_handler({i}, frame, 0);}}\n"
            for i in range(256)
            if i not in ERROR_CODE_VECTORS
        )
        f.writelines(
            f"__attribute__((interrupt)) void idt_{i}(IntFrame *frame, uint64_t error){{common_handler({i}, frame, error);}}\n"
            for i in ERROR_CODE_VECTORS
        )
        f.write("""
void make_idt(){
    uint16_t cs = 0x18;
    asm volatile("mov %%cs, %0" : "=r"(cs));
""")
        f.writelines(
            f"/**/idt_set_gate({i}, (uint64_t)idt_{i}, cs, {0x8E});\n" for i in range(256)
        )
        f.write("}")


objs = []
for cpp in glob("src/kernel/**/*.cpp"):
    obj_name = f"build/kernel/{n(cpp)}.o"
    objs.append(obj_name)
    d.trace("g++", cpp)
    d.add(obj_name, cpp, gxx_elf)


for c in glob("src/kernel/**/*.c"):
    obj_name = f"build/kernel/{n(c)}.o"
    objs.append(obj_name)
    d.trace("gcc", c)
    if c == "src/kernel/system/idt.c":
        d.add(obj_name, c, gcc_nosse)
    else:
        d.add(obj_name, c, gcc_elf)

for asm in glob("src/kernel/**/*.asm"):
    obj_name = f"build/kernel/{n(asm)}.o"
    objs.append(obj_name)
    d.add(obj_name, asm, nasm_elf)

d.add("build/kernel/kernel.elf", objs, lambda *a: ld_link(*a, "src/kernel/linker.ld"))
