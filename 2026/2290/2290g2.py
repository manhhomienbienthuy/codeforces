# author: manhhomienbienthuy
# created: 2026-11-13T00:46:52+00:00
# https://codeforces.com/contest/2290/problem/G2

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    h = list(map(int, input().split()))
    mid = h.index(max(h))
    h = h[mid:] + h[:mid]

    lo = 0
    hi = max(abs(h[i] - h[i - 1]) for i in range(n))

    def check(m):
        need = [0] * n
        for i in range(1, n):
            target = h[i - 1] + need[i - 1] - m
            if h[i] < target:
                need[i] = target - h[i]

        for i in range(n - 1, 0, -1):
            target = h[(i + 1) % n] + need[(i + 1) % n] - m
            if h[i] + need[i] < target:
                need[i] += target - h[i] - need[i]

        return sum(need) <= k

    while lo <= hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid - 1
        else:
            lo = mid + 1
    print(lo)
