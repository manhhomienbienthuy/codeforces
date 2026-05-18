t = int(input())
for _ in range(t):
    n = int(input())
    tree = [[] for _ in range(n + 1)]
    cnt = [0] * (n + 1)
    for _ in range(n-1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)
        cnt[u] += 1
        cnt[v] += 1

    if n == 2:
        print(0)
        continue

    leaves = sum(cnt[i] == 1 for i in range(1, n + 1))
    ans = 10**18
    for u in range(1, n + 1):
        around = sum(cnt[v] == 1 for v in tree[u])
        ans = min(ans, leaves - around)

    print(ans)
