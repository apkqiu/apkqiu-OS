from builder import *

d = MakeConfig()

@d.register("build/boot/boot.bin", ["src/boot/boot.asm"])
def nasm_bin(dst, src):
    execute("nasm", src[0], "-f", "bin", "-o", dst, "-Isrc/boot")

d.trace("nasm", "src/boot/boot.asm")

@d.register("build/boot/loader.bin", ["src/boot/loader.asm"])
def nasm_bin1(dst, src):
    execute("nasm", src[0], "-f", "bin", "-o", dst, "-Isrc/boot")

d.trace("nasm", "src/boot/loader.asm")