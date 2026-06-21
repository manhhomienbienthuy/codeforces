t = int(input())
for _ in range(t):
    n, k = map(int, input().split())

    casino = []
    for i in range(n):
        l, r, real = map(int, input().split())
        casino.append((l, r, real))
    casino = sorted(casino)
    i = 0
    while True:
        m = set()
        while i < n:
            l, r, real = casino[i]
            if l > k:
                break
            if k <= r:
                m.add(real)
            i += 1
        if not m:
            break
        m = max(m)
        if m <= k:
            break
        k = m
    print(k)
