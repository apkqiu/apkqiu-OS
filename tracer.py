import shlex

from builder import *
from consts import *

@define_tracer("file")
def trace_file(file: str):
    return []

@define_tracer("gcc")
def trace_gcc(file: str):
    out = execute_capture(
        "gcc",
        "-MM",
        "-Isrc/include",
        "-Isrc/include/std",
        file
    )
    x = shlex.split(out[out.index(":"):])
    return [i for i in x[1:] if i not in (file,'\n')]

@define_tracer("g++")
def trace_gxx(file: str):
    out = execute_capture(
        "g++",
        "-MM",
        "-Isrc/include",
        "-Isrc/include/std",
        file
    )
    x = shlex.split(out[out.index(":"):])
    return [i for i in x[1:] if i not in (file,'\n')]

@define_tracer("nasm")
def trace_nasm(file: str):
    out = execute_capture(
        "nasm",
        "-M",
        "-Isrc/boot",
        file
    )
    x = shlex.split(out[out.index(":"):])
    return [i for i in x[1:] if i not in (file,'\n')]


