# author: manhhomienbienthuy
# created: 2026-11-12T14:42:02+00:00
# https://codeforces.com/contest/2290/problem/C

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    h = sorted(map(int, input().split()))

    cur = -1

    left, right = [], []
    ans = 0
    flag = False

    for x in h:
        if x != cur:
            flag = False
            ans += 1
            cur = x
            left.append(x)
        else:
            ans += not flag
            flag = True
            right.append(x)

    print(ans)
    print(*left, *right[::-1])
