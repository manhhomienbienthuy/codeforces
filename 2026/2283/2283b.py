# author: manhhomienbienthuy
# created: 2026-11-06T05:09:56+00:00
# https://codeforces.com/contest/2283/problem/B

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    ans = n
    for x in a:
        cnt = 0
        for y in a:
            cnt += y % x > 0
        ans = min(ans, cnt)

    print(ans)
