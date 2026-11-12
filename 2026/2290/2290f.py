# author: manhhomienbienthuy
# created: 2026-11-12T15:19:26+00:00
# https://codeforces.com/contest/2290/problem/F

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    b = list(map(int, input().split()))

    p = [0] * n

    for x in range(1, n + 1):
        pos = b[x - 1] - x + n + 1

        if pos < 1 or pos > n or p[pos - 1] != 0:
            print(-1)
            break

        p[pos - 1] = x
    else:
        print(*p)
