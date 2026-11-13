# author: manhhomienbienthuy
# created: 2026-11-13T04:52:13+00:00
# https://codeforces.com/contest/2290/problem/H

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    g = [[] for i in range(n)]

    for i in range(n - 1):
        u, v = map(int, input().split())
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)

    parent, size = [-1] * n, [1] * n
    stack = [(0, 0)]

    while stack:
        v, state = stack.pop()
        if not state:
            stack.append((v, 1))
            for u in g[v]:
                if u == parent[v]:
                    continue
                parent[u] = v
                stack.append((u, 0))
        else:
            for u in g[v]:
                if u == parent[v]:
                    continue
                size[v] += size[u]

    ans = 0

    for v in range(n):
        m1, m2, m3 = 0, 0, 0

        for u in g[v]:
            if u == parent[v]:
                continue
            sz = size[u]
            if sz > m1:
                m1, m2, m3 = sz, m1, m2
            elif sz > m2:
                m2, m3 = sz, m2
            elif sz > m3:
                m3 = sz

        if v == 0:
            ans = max(ans, m3)
        else:
            ans = max(ans, m2)

    print(n - ans)
