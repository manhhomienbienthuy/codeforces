#!/usr/bin/env python3

n = eval(input())
i = 0
while n >= 0:
    i += 1
    bricks = i * (i + 1) // 2
    n -= bricks
print(i - 1)
