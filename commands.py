from builder import *

c = MakeConfig()

@c.command("clean")
def clean():
    execute("rm", "-rfv", "build", ".cache.json")


@c.command("run")
def run():
    execute("rm", "qemu-run.log", check=False)
    execute(
        "qemu-system-x86_64",
        ("-drive", "file=./os.img,format=raw,if=ide"),
        ("-boot", "order=c"),
        ("-m", "1G"),
        # 调试
        "--no-shutdown",
        "--no-reboot",
        ("-monitor", "stdio"),  # 控制台
        # -s -S
        ("-display", "gtk,show-tabs=on,zoom-to-fit=on"), 
        # 减速
        # ("-icount","shift=10,sleep=on,align=on"),
        ("-d", "in_asm,int,guest_errors,unimp,mmu"),
        ("-D", "qemu-run.log"),
    )