#!/usr/bin/env python3

a, b = map(int, input().split())

step = 0
while b > 0:
    step += a // b
    a, b = b, a % b
print(step)
