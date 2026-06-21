#!/usr/bin/env python3

n, k = map(int, input().split())
a = [input() for _ in range(n)]
SAMPLE = "0123456789"

compare = set(list(SAMPLE[:k + 1]))
result = 0
for c in a:
    tmp = set(list(c))
    if compare.issubset(tmp):
        result += 1

print(result)
