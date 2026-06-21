t = int(input())
for _ in range(t):
    n = int(input())
    tree = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    dp = [[False] * 3 for i in range(n + 1)]
    stack1 = [(1, -1)]
    stack2 = []
    while stack1:
        u, p = stack1.pop()
        stack2.append((u, p))
        for v in tree[u]:
            if v == p:
                continue
            stack1.append((v, u))
    while stack2:
        u, p = stack2.pop()
        is_leaf = True
        cur = [False] * 3
        cur[0] = True

        for v in tree[u]:
            if v == p:
                continue
            is_leaf = False

            nxt = [False] * 3
            for i in range(3):
                if not cur[i]:
                    continue
                for j in range(3):
                    if dp[v][j]:
                        nxt[(i + j) % 3] = True
            cur = nxt

        dp[u][1] = True
        if not is_leaf:
            for i in range(3):
                if cur[i]:
                    dp[u][i] = True

    print('YES' if dp[1][0] else 'NO')
