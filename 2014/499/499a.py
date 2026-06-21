#!/usr/bin/env python3

n, x = map(int, input().split())

res = 0
prev = 1
for _ in range(n):
    l, r = map(int, input().split())
    left = prev + (l - prev) // x * x
    res += r - left + 1
    prev = r + 1

print(res)
