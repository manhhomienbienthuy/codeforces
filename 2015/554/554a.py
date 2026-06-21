#!/usr/bin/env python3

s = input()

print(sum(len(s) + 1 - s.count(chr(ord('a') + i)) for i in range(26)))
