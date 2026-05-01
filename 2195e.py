MOD = 10**9 + 7

t = int(input())
for _ in range(t):
    n = int(input())
    tree = [tuple(map(int, input().split())) for i in range(n)]
    b = [0] * (n + 1)
    dp = [0] * (n + 1)
    q = []

    stack = [1]
    while stack:
        v = stack.pop()
        q.append(v)
        l, r = tree[v - 1]
        if l:
            stack.append(l)
            stack.append(r)

    for v in q[::-1]:
        l, r = tree[v - 1]
        if l == r == 0:
            b[v] = 1
        else:
            b[v] = (3 + b[l] + b[r]) % MOD

    dp[1] = b[1]
    for v in q:
        for child in tree[v - 1]:
            if child:
                dp[child] = (dp[v] + b[child]) % MOD

    print(*dp[1:])
