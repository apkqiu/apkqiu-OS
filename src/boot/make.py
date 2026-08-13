from builder import *

d = MakeConfig()


@d.rule("build/boot/boot.bin", ["src/boot/boot.asm"])
def nasm_bin(dst, src):
    execute("nasm", src[0], "-f", "bin", "-o", dst, "-Isrc/boot")


d.trace_rule("nasm", "src/boot/boot.asm")
