t = int(input())
for _ in range(t):
    n = int(input())
    tree = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    c = next((i for i in range(1, n + 1) if len(tree[i]) == 2), -1)
    if c == -1:
        print("NO")
        continue

    print("YES")

    def dfs(u, p, d):
        stack = [(u, p, d)]
        while stack:
            u, p, d = stack.pop()
            if d:
                print(u, p)
            else:
                print(p, u)
            for v in tree[u]:
                if v == p:
                    continue
                stack.append((v, u, d ^ 1))

    a, b = tree[c]
    dfs(a, c, 0)
    dfs(b, c, 1)
