#!/usr/bin/env python

n = int(input())

a = []
p = []

for _ in range(n):
    x, y = map(int, input().split())
    a.append(x)
    p.append(y)

total = 0
current = 0

for i in range(n):
    need = a[i]
    if current < need:
        for j in range(i + 1, n):
            if p[j] < p[i]:
                break
        else:
            j = n
        need = sum(a[i:j])
        # print("i =", i, "j =", j)
        # print("need =", need, "current =", current)
        total += (need - current) * p[i]
        current = need - a[i]
    else:
        current = current - need

print(total)
