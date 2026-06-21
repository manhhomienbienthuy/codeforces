t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    d = [abs(p[i] - p[i - 1]) for i in range(1, n)]
    e = sorted([(d[i], i) for i in range(n - 1)], reverse=True)
    parent = list(range(n))
    size = [1] * n

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(a, b):
        ra, rb = find(a), find(b)
        if ra == rb:
            return 0
        if size[ra] < size[rb]:
            ra, rb = rb, ra
        parent[rb] = ra
        contrib = size[ra] * size[rb]
        size[ra] += size[rb]
        return contrib

    ans = [0] * n
    cur = 0
    i = 0
    for j in range(n - 1, 0, -1):
        while i < n-1 and e[i][0] >= j:
            k = e[i][1]
            cur += union(k, k+1)
            i += 1
        ans[j] = cur
    print(*ans[1:])
