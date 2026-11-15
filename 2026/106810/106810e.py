# author: manhhomienbienthuy
# created: 2026-11-15T06:57:03+00:00
# https://codeforces.com/gym/106810/problem/E

import sys
input = sys.stdin.readline

lim = 100
masks = [[0] * i for i in range(lim + 1)]

for m in range(2, lim + 1):
    masks[m] = [0] * m

    for x in range(m):
        mask = 0

        for y in range(m):
            if x * y * (x * y) * (x - y) % m == 0:
                mask |= 1 << y

        masks[m][x] = mask


t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    for _ in range(q):
        l, r, m = map(int, input().split())
        l -= 1
        r -= 1

        pos = [-1] * m
        seen = 0
        ans_i, ans_j = -1, -1

        hi = min(r, l + m)

        for i in range(l, hi + 1):
            x = a[i] % m
            hit = masks[m][x] & seen

            if hit:
                bit = hit & -hit
                y = bit.bit_length() - 1

                ans_i = pos[y]
                ans_j = i
                break

            if pos[x] == -1:
                pos[x] = i
                seen |= 1 << x

        if ans_i == -1:
            print(-1)
        else:
            print(ans_i, ans_j)
