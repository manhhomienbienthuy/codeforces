# author: manhhomienbienthuy
# created: 2026-11-12T14:38:18+00:00
# https://codeforces.com/contest/2290/problem/B

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()

    ans = 0
    color = "RB"
    cur = 0
    for c in s:
        ans += c != color[cur]
        cur = 1 if c == 'R' else 0
    print(ans)
