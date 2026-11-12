# author: manhhomienbienthuy
# created: 2026-11-12T14:55:36+00:00
# https://codeforces.com/contest/2290/problem/D

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()

    used = [False] * 26

    for i in range(n // 2):
        x = ord(s[i]) - ord('a')
        y = ord(s[n - 1 - i]) - ord('a')

        if x > y:
            x, y = y, x

        for j in range(x + 1, y + 1):
            used[j] = True

    print(sum(used))
