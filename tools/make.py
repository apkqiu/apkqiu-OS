# 构建跨平台工具链

import multiprocessing
import os
from concurrent.futures import *

from builder import *

c = MakeConfig()
GCC_URL = "https://ftp.gnu.org/gnu/gcc/gcc-16.1.0/gcc-16.1.0.tar.xz"
BINUTILS_URL = "https://ftp.gnu.org/gnu/binutils/binutils-2.47.tar.lz"

# China
if True:
    GCC_URL = "https://mirrors.aliyun.com/gnu/gcc/gcc-16.1.0/gcc-16.1.0.tar.xz"
    BINUTILS_URL = "https://mirrors.aliyun.com/gnu/binutils/binutils-2.47.tar.lz"

GCC_PATH = ("build/gcc", "gcc-16.1.0")
BINUTILS_PATH = ("build/binutils", "binutils-2.47")


PREFIX = os.path.abspath("tools/prefix")


MAKE_FLAGS = ("-j", min(8, multiprocessing.cpu_count()))

env = os.environ.copy()
env["PATH"] = f"{PREFIX}/bin:{env['PATH']}"


def build_compiler_for(TARGET, ts):
    BINUTILS_BUILD = BINUTILS_PATH[0] + "/" + TARGET
    GCC_BUILD = GCC_PATH[0] + "/" + TARGET
    os.makedirs("build", exist_ok=True)
    os.makedirs(PREFIX, exist_ok=True)
    os.makedirs(GCC_BUILD, exist_ok=True)
    os.makedirs(BINUTILS_BUILD, exist_ok=True)

    wait([ts[0]])  # binutils
    execute(
        "../" + BINUTILS_PATH[1] + "/configure",
        f"--target={TARGET}",
        f"--prefix={PREFIX}",
        "--with-sysroot",
        "--disable-nls",
        "--disable-werror",
        "--enable-default-execstack=no",
        cwd=BINUTILS_BUILD,
    )
    execute(
        "make",
        MAKE_FLAGS,
        cwd=BINUTILS_BUILD,
    )
    execute(
        "make",
        "install",
        cwd=BINUTILS_BUILD,
    )
    wait([ts[1]])  # gcc
    execute(
        "../" + GCC_PATH[1] + "/configure",
        f"--target={TARGET}",
        f"--prefix={PREFIX}",
        "--disable-nls",
        "--enable-languages=c,c++",
        "--without-headers",
        "--enable-initfini-array",
        "--disable-hosted-libstdcxx",
        cwd=GCC_BUILD,
    )
    for i in ["gcc", "target-libgcc", "target-libstdc++-v3"]:
        execute(
            "make",
            f"all-{i}",
            MAKE_FLAGS,
            cwd=GCC_BUILD,
        )
        execute(
            "make",
            f"install-{i}",
            cwd=GCC_BUILD,
        )


def build_compilers():
    t = ThreadPoolExecutor(4)

    def download_binutils():
        if not os.path.exists("build/binutils.tar.lz"):
            execute("curl", BINUTILS_URL, "-o", "build/binutils.tar.lz")
        if not os.path.exists("build/binutils"):
            os.makedirs(BINUTILS_PATH[0], exist_ok=True)
            execute("tar", "-xavf", "build/binutils.tar.lz", "-C", "build/binutils")

    def download_gcc():
        if not os.path.exists("build/gcc.tar.lz"):
            execute("curl", GCC_URL, "-o", "build/gcc.tar.lz")
        if not os.path.exists("build/gcc"):
            os.makedirs(GCC_PATH[0], exist_ok=True)
            execute("tar", "-xavf", "build/gcc.tar.lz", "-C", "build/gcc")
            # patch it!
            with open(
                os.path.join(
                    GCC_PATH[0], GCC_PATH[1], "gcc", "config", "i386", "t-x86_64-elf"
                ),
                "a",
            ) as f:
                f.write("""
# libgcc without red zone

MULTILIB_OPTIONS += mno-red-zone
MULTILIB_DIRNAMES += no-red-zone
""")

            c = []
            with open(
                os.path.join(GCC_PATH[0], GCC_PATH[1], "gcc", "config.gcc"), "r"
            ) as f:
                c = f.readlines()

            c.insert(
                c.index("x86_64-*-elf*)\n") + 1,
                '\ttmake_file = " ${tmake_file} i386/t-x86_64-elf"\n',
            )
            with open(
                os.path.join(GCC_PATH[0], GCC_PATH[1], "gcc", "config.gcc"), "w"
            ) as f:
                f.writelines(c)

    a = t.submit(download_binutils), t.submit(download_gcc)
    # wait(a)

    for target in ("i686-elf", "x86_64-elf"):
        t.submit(build_compiler_for, target, a)
    t.shutdown(True)


def destroy_compilers():
    # 嘻嘻，只有磁盘不足的杂鱼才会用！
    if input("确定要毁灭编译器吗，zako？(y/N) ").lower() != "y":
        return
    for i in (BINUTILS_PATH[0], GCC_PATH[0], PREFIX):
        execute("rm", "-rfv", i)


c.commands["destroy-compilers"] = destroy_compilers
c.commands["build-compilers"] = build_compilers
