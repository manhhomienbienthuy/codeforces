#!/usr/bin/env python3

n = int(input())
m = int(input())

a = sorted([int(input()) for _ in range(n)], reverse=True)

sum = 0
for i in range(n):
    sum += a[i]
    if sum >= m:
        break
print(i + 1)
