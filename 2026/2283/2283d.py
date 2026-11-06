# author: manhhomienbienthuy
# created: 2026-11-06T05:17:54+00:00
# https://codeforces.com/contest/2283/problem/D

import sys
from array import array
input = sys.stdin.readline

t = int(input())
out = []

for _ in range(t):
    n = int(input())

    if n % 2 == 0:
        for _ in range(n - 1):
            input()

        print(n + 1)
        continue

    head = array('i', [-1]) * n
    to = array('i')
    nxt = array('i')

    def add_edge(u, v):
        to.append(v)
        nxt.append(head[u])
        head[u] = len(to) - 1

    for _ in range(n - 1):
        u, v = map(int, input().split())
        u -= 1
        v -= 1

        add_edge(u, v)
        add_edge(v, u)

    cand = [
        (n, n - 1),
        (n + 1, n // 2),
        (n + 2, 0),
    ]

    ans = n

    for k, x in cand:
        comp = array('i', [-1]) * n
        comp[x] = -2

        e = head[x]
        cid = 0

        while e != -1:
            root = to[e]

            if comp[root] == -1:
                comp[root] = cid
                stk = [root]

                while stk:
                    v = stk.pop()
                    j = head[v]

                    while j != -1:
                        u = to[j]

                        if comp[u] == -1:
                            comp[u] = cid
                            stk.append(u)

                        j = nxt[j]

                cid += 1

            e = nxt[e]

        gray = False

        for u in range(n):
            v = k - u - 2

            if v < 0 or v >= n or u >= v:
                continue

            if comp[u] != comp[v]:
                gray = True
                break

        if gray:
            ans = k
            break

    print(ans)
