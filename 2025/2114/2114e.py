t = int(input())
for _ in range(t):
    n = int(input())
    a = [0] + list(map(int, input().split()))
    g = [[] for i in range(n + 1)]
    for i in range(n - 1):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    ans = a[:]
    d = a[:]

    stack = [(1, 0)]
    while stack:
        u, p = stack.pop()
        ans[u] = max(ans[u], a[u] - d[p])
        d[u] = min(d[u], a[u] - ans[p])
        for v in g[u]:
            if v == p:
                continue
            stack.append((v, u))

    print(*ans[1:])
