from builder import *
from consts import *

d = MakeConfig()


def gxx_elf(dst, src):
    execute(
        X86_64.CXX,
        X86_64.CFLAGS,
        *src,
        "-o",
        dst,
    )


def gcc_elf(dst, src):
    execute(
        X86_64.CC,
        X86_64.CFLAGS,
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
for cpp in glob("src/long/**/*.cpp"):
    obj_name = f"build/long/{n(cpp)}.o"
    objs.append(obj_name)
    d.trace("g++", cpp)
    d.add(obj_name, cpp, gxx_elf)

for c in glob("src/long/**/*.c"):
    obj_name = f"build/long/{n(c)}.o"
    objs.append(obj_name)
    d.trace("gcc", c)
    d.add(obj_name, c, gcc_elf)

for asm in glob("src/long/**/*.asm"):
    obj_name = f"build/long/{n(asm)}.o"
    objs.append(obj_name)
    d.add(obj_name, asm, nasm_elf)

d.add("build/long/long.elf", objs, lambda *a: ld_link(*a, "src/long/linker.ld"))
d.add("build/long/long.bin", "build/long/long.elf", objcopy)
