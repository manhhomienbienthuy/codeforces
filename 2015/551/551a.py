#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))

sorted_a = list(sorted(a, reverse=True))
for i in range(n):
    print(1 + sorted_a.index(a[i]), end=" ")
