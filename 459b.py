#!/usr/bin/env python3

n = int(input())
b = sorted(map(int, input().split()))

if b[-1] - b[0]:
    i = 1
    while i < n and b[i] == b[0]:
        i += 1
    min_cnt = i
    i = n-2
    while i > 0 and b[i] == b[-1]:
        i -= 1
    max_cnt = n - 1 - i
    print(b[-1] - b[0], min_cnt*max_cnt)
else:
    print(0, n*(n-1)//2)
