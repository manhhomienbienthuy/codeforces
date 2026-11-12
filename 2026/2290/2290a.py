# author: manhhomienbienthuy
# created: 2026-11-12T14:35:12+00:00
# https://codeforces.com/contest/2290/problem/A

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    a, b, c = sorted(map(int, input().split()))
    print("YES" if a + 1 == b == c - 1 else "NO")
