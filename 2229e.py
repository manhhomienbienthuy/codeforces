MOD = 998244353

t = int(input())
for _ in range(t):
    n = int(input())
    g = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)

    mx = [0] * (n + 1)
    parent = [0] * (n + 1)

    stack = [(n, -1, 0)]
    while stack:
        u, p, state = stack.pop()
        if state == 0:
            stack.append((u, p, 1))
            for v in g[u]:
                if v == p:
                    continue
                parent[v] = u
                stack.append((v, u, 0))
        else:
            mx[u] = u
            for v in g[u]:
                if v == p:
                    continue
                mx[u] = max(mx[u], mx[v])

    mx2 = [0] * (n + 1)
    for u in range(1, n + 1):
        m = 0
        for v in g[u]:
            if v != parent[u]:
                m = max(m, mx[v])
        mx2[u] = m

    ok = [False] * (n + 1)
    ok[n] = True
    for v in g[n]:
        if mx[v] < n - 1:
            continue
        stack = [(v, n)]
        while stack:
            u, p = stack.pop()
            ok[u] = True
            for v in g[u]:
                if v == p:
                    continue
                stack.append((v, u))
        flag = False
        for i in range(n - 1, -1, -1):
            if flag and ok[i]:
                ok[i] = False
            if not flag and ok[i] == False:
                flag = True

    dp = [0] * (n + 1)
    pref = [0] * (n + 1)
    idx = -1
    for i in range(n, -1, -1):
        if len(g[i]) == 1:
            idx = i
            break
    dp[idx] = 1
    pref[idx] = 1

    for i in range(idx + 1, n + 1):
        l = mx2[i]
        if l + 1 < i:
            dp[i] = pref[i - 1] - pref[l]
        pref[i] = pref[i - 1] + dp[i]

    print(sum(dp[i] for i in range(n + 1) if ok[i]) % MOD)
