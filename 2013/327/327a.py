#!/usr/bin/env python

n = input()
a = map(int, raw_input().split())

max_cnt = 0
for i in range(n):
    for j in range(i, n):
        count = a[:i].count(1) + a[i:j+1].count(0) + a[j+1:].count(1)
        if count > max_cnt:
            max_cnt = count
print max_cnt
