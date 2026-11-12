# author: manhhomienbienthuy
# created: 2026-11-12T15:03:40+00:00
# https://codeforces.com/contest/2290/problem/E

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    w = [0] * n
    s = 0
    pref = 0

    for i in range(n):
        pref ^= w[i - 1]
        if i > k:
            pref ^= w[i - k - 1]

        w[i] = 1 ^ pref
        s ^= (a[i] & 1) & w[i]

    if s:
        print("Alice")
    else:
        print("Bob")
