# author: manhhomienbienthuy
# Python template for Codeforces

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = input().strip()
    x, y = map(int, input().split())


def count_digits(n):
    cnt = [0] * 10
    pos = 1

    while pos <= n:
        high = n // (pos * 10)
        cur = (n // pos) % 10
        low = n % pos

        for d in range(1, 10):
            if d < cur:
                cnt[d] += (high + 1) * pos
            elif d == cur:
                cnt[d] += high * pos + low + 1
            else:
                cnt[d] += high * pos

        if high > 0:
            if cur == 0:
                cnt[0] += (high - 1) * pos + low + 1
            else:
                cnt[0] += high * pos

        pos *= 10

    return cnt
