#!/usr/bin/python

from builder import *

d = MakeConfig()
import tracer  # noqa: F401

d.include("commands.py")
d.subdir("src")

