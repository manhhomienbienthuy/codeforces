#!/usr/bin/env python3

n, m = [int(i) for i in input().split()]
dic = dict(input().split() for _ in range(m))
for s in input().split():
    t = dic[s]
    print(s if len(s) <= len(t) else t, end=" ")
