# author: manhhomienbienthuy
# created: 2026-11-06T05:06:08+00:00
# https://codeforces.com/contest/2283/problem/A

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    l, r = map(int, input().split())
    if l > 0 or r < 0:
        print(r - l)
    else:
        print(max(0, abs(r + l) - 1))
