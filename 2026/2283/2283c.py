# author: manhhomienbienthuy
# created: 2026-11-06T05:12:00+00:00
# https://codeforces.com/contest/2283/problem/C

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())

    m = 0
    if n % 4 == 0:
        m = n
    elif n % 4 == 1:
        m = 1
    elif n % 4 == 2:
        m = n + 1

    ans = [0] * n
    for i in range(n, 0, -1):
        if m ^ i ^ (i << 1) > m:
            ans[i - 1] = 1
            m ^= i ^ (i << 1)

    print(*ans)
