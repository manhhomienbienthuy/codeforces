#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))

pay = a[0]
energy = 0
for i in range(1, n):
    energy += a[i-1] - a[i]
    if energy < 0:
        pay -= energy
        energy = 0
print(pay)
