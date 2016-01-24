#!/usr/bin/env python3

n, k = map(int, input().split())
s = [c for c in input()]
charset = set(s)
x = list(map(s.count, charset))
print(x)
