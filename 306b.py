#!/usr/bin/env python3

n, m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(m)]

res = []

def inside(s, a):
    for k in range(a[0], a[0] + a[1]):
        if s[k-1] == 0:
            return False
    return True

for i in range(m):
    cov = [0 for i in range(n)]
    for j in range(m):
        if i != j and j not in res:
            for k in range(a[j][0], a[j][0] + a[j][1]):
                cov[k - 1] = 1
    if inside(cov, a[i]):
        res.append(i)

print(len(res))
for i in res:
    print(i + 1, end=' ')

