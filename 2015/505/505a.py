#!/usr/bin/env python3

from string import ascii_lowercase
import sys


def is_palindrome(x):
    return x == x[::-1]


s = [c for c in input()]

for c in ascii_lowercase:
    for i in range(len(s) + 1):
        new_s = s[:i] + [c] + s[i:]
        if is_palindrome(new_s):
            print("".join(new_s))
            sys.exit(0)
print("NA")
