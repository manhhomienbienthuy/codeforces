#!/usr/bin/env python3

s = input().lower()
for c in "aoyeui":
    s = s.replace(c, "")
for c in s:
    print(".", c, sep="", end="")
