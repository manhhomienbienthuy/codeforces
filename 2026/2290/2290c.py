# author: manhhomienbienthuy
# created: 2026-11-12T14:42:02+00:00
# https://codeforces.com/contest/2290/problem/C

import sys
from collections import Counter
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    h = list(map(int, input().split()))

    cnt = Counter(h)
    vals = sorted(cnt)

    left = []
    mid = []
    right = []

    for x in vals:
        left.append(x)

        if cnt[x] > 2:
            mid += [x] * (cnt[x] - 2)

    for x in reversed(vals):
        if cnt[x] >= 2:
            right.append(x)

    print(sum(min(c, 2) for c in cnt.values()))
    print(*left, *mid, *right)
