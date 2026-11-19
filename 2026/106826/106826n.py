# author: manhhomienbienthuy
# created: 2026-11-19T01:05:52+00:00
# https://codeforces.com/gym/106826/problem/N

import sys
input = sys.stdin.readline

a, b, x, y = map(int, input().split())
ans = max(x, y) + max(a - x, b - y)
print(ans)
