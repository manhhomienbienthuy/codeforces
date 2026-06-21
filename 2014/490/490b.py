#!/usr/bin/env python3

n = int(input())
after, before = {}, {}
for _ in range(n):
    a, b = map(int, input().split())
    after[a], before[b] = b, a

result = []
for i in after:
    if i not in before:
        result.append(i)
result.append(after.get(0))
for i in range(2, n):
    result.append(after.get(result[i - 2]))
print(*result)
