#!/usr/bin/env python3

n = int(input())
a = list(map(int, input().split()))

print(max([min([a[i] - a[i-2] for i in range(2, n)])] + [a[i] - a[i-1] for i in range(1, n)]))
