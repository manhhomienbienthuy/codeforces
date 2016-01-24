#!/usr/bin/env python3

n, l = map(int, input().split())
a = list(sorted(map(int, input().split())))
try:
    d = max([a[i] - a[i - 1] for i in range(1, n)])
except ValueError:
    d = 0
print(max(a[0], l - a[-1], d/2))
