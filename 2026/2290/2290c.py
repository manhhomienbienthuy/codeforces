# author: manhhomienbienthuy
# created: 2026-11-12T14:42:02+00:00
# https://codeforces.com/contest/2290/problem/C

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    h = sorted(map(int, input().split()))

    left, right = [], []
    ans = 0

    i = 0
    while i < n:
        left.append(h[i])

        j = i + 1
        while j < n and h[j] == h[i]:
            right.append(h[i])
            j += 1

        ans += min(2, j - i)
        i = j

    print(ans)
    print(*left, *right[::-1])
