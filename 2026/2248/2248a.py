# author: manhhomienbienthuy
# created: 2026-08-02T02:49:11+00:00
# https://codeforces.com/contest/2248/problem/A

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input().strip()
    s = s.replace('0', '', 1)
    s = s.replace('1', '', 1)
    print(s)
