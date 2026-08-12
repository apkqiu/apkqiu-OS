
from builder import *

d = MakeConfig()



def hex(val: int, len=8):
    return "0x" + __builtins__["hex"](val)[2:].rjust(len, "0")

@d.register("os.img", "build/boot/boot.bin, build/long/long.bin, build/kernel/kernel.elf")
def make_image(dst, src):
    with open(dst, "wb") as f:
        f.seek(0)
        print(hex(f.tell()), src[0])
        f.write(open(src[0], "rb").read())
        f.seek(((f.tell()+511) // 512) * 512)
        print(hex(f.tell()), src[1])
        f.write(open(src[1], "rb").read())
        print(hex(f.tell()))

        f.seek(512 * 64)
        print(hex(f.tell()), src[2])
        f.write(open(src[2], "rb").read())
        print(hex(f.tell()))
        # 扩容至1GB
        f.seek(2 * 1024 * 1024 * 1024)
        f.seek(-1, 1)
        f.write(b"\x00")
d.default = "os.img"

d.subdir("boot")
d.subdir("kernel")
d.subdir("long")