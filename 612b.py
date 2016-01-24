#!/usr/bin/env python3

n = int(input())
f = list(map(int, input().split()))
ff = [0] * n

for i, e in enumerate(f):
    ff[e - 1] = i

print(sum(abs(ff[i + 1] - ff[i]) for i in range(n - 1)))
