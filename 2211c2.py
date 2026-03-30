from collections import Counter


t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    parent = list(range(n))

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(x, y):
        rx, ry = find(x), find(y)
        if rx != ry:
            parent[ry] = rx

    for j in range(n - k):
        if a[j] == a[j + k]:
            union(j, j + k)

    comp_val = {}
    ok = True

    for j in range(n - k):
        if a[j] != a[j + k]:
            rj = find(j)
            rjk = find(j + k)
            comp_val[rj] = a[j]
            comp_val[rjk] = a[j + k]

    if ok:
        for i in range(n):
            if b[i] != -1:
                ri = find(i)
                if ri in comp_val:
                    if comp_val[ri] != b[i]:
                        ok = False
                        break
                else:
                    comp_val[ri] = b[i]

    if ok:
        target = Counter(a[:k])
        free_count = 0

        for i in range(k):
            ri = find(i)
            if ri in comp_val:
                v = comp_val[ri]
                if target[v] <= 0:
                    ok = False
                    break
                target[v] -= 1
            else:
                free_count += 1

    if ok:
        remaining = sum(v for v in target.values() if v > 0)
        if remaining != free_count:
            ok = False

    print("YES" if ok else "NO")
