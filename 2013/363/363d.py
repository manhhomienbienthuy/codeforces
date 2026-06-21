#!/usr/bin/env python3

n, m, a = map(int, input().split())
b = sorted(map(int, input().split()))
p = sorted(map(int, input().split()))

for i in range(1, min(n, m)):
    if a < sum(max(0, x - y) for x, y in zip(p[:i], b[-i:])):
        break
print(i, max(0, sum(p[:i]) - a))
