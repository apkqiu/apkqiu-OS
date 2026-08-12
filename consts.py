import os


class EnvironmentConfig:
    def __init__(self):
        self.ARCH: str = ""
        self.CFLAGS: list[str | tuple[str]] = []
        self.CC = self.CXX = self.LD = self.OBJCOPY = ""

    def use(self, tool: str):
        return f"tools/prefix/{self.ARCH}-{tool}"

    def list(self):
        return [
            i.removeprefix(f"{self.ARCH}-")
            for i in os.listdir("tools/prefix/")
            if i.startswith(f"{self.ARCH}-")
        ]


ARCH_SPECIFIC_CONFIGS = {"x86_64": {"CFLAGS": ("-mno-red-zone")}}


def env(arch: str):
    cfg = EnvironmentConfig()
    cfg.ARCH = arch
    cfg.CC = cfg.use("gcc")
    cfg.CXX = cfg.use("g++")
    for i in cfg.list():
        setattr(cfg, i.upper().replace("-","_"), cfg.use(i))
    cfg.CFLAGS = [
        "-ffreestanding",
        "-c",
        "-Wall",
        "-fno-stack-protector"
    ]
    if arch == "x86_64":
        cfg.CFLAGS.append("-mno-red-zone")

    return cfg


X86_64 = env("x86_64-elf")
I686 = env("i686-elf")
