from builder import *
from consts import *

d = MakeConfig()


def gcc_elf(dst, src):
    execute(
        X86_64.CC,
        X86_64.CFLAGS,
        "-mcmodel=large",
        "-Os",
        (
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


def objcopy(dst, src):
    execute("objcopy", "-O", "binary", *src, dst)


objs = []

for c in glob("src/long/**/*.c"):
    obj_name = f"build/long/{n(c)}.o"
    objs.append(obj_name)
    d.trace_rule("gcc", c)
    d.add_rule(obj_name, c, gcc_elf)

for asm in glob("src/long/**/*.asm"):
    obj_name = f"build/long/{n(asm)}.o"
    objs.append(obj_name)
    d.add_rule(obj_name, asm, nasm_elf)

d.add_rule("build/long/long.elf", objs, lambda *a: ld_link(*a, "src/long/linker.ld"))
d.add_rule("build/long/long.bin", "build/long/long.elf", objcopy)
