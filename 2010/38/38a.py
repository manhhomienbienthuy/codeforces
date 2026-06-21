#!/usr/bin/env python3

n = int(input())
d = list(map(int, input().split()))
a, b = map(int, input().split())

print(sum(d[i-1] for i in range(a, b)))
