t = int(input())
for _ in range(t):
    n, k, x = map(int, input().split())
    a = [-1] + sorted(map(int, input().split())) + [-1]
    d = [a[i + 1] - a[i] + 1 for i in range(n + 1)]
    l, r = 0, x + 1
    while l <= r:
        m = (l + r) // 2
        d[0] = a[1] + m + 1
        d[-1] = x - a[n] + m + 1
        s = sum(max(0, d[i] - 2 * m) for i in range(n + 1))
        if s >= k:
            l = m + 1
        else:
            r = m - 1
    if r == 0:
        print(*range(k))
        continue
    a[0] = -r
    a[-1] = x + r
    ans = []
    for i in range(n + 1):
        if d[i] > 2 * r:
            ans += list(range(a[i] + r, a[i + 1] - r + 1))
            if len(ans) >= k:
                break
    print(*ans[:k])
