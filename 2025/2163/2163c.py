t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = 0
    min_a = [a[0]] * n
    max_a = [a[0]] * n
    for i in range(1, n):
        min_a[i] = min(min_a[i - 1], a[i])
        max_a[i] = max(max_a[i - 1], a[i])
    min_b = [b[n - 1]] * n
    max_b = [b[n - 1]] * n
    for i in range(n - 2, -1, -1):
        min_b[i] = min(min_b[i + 1], b[i])
        max_b[i] = max(max_b[i + 1], b[i])
    segs = []

    for i in range(n):
        segs.append((min(min_a[i], min_b[i]), max(max_a[i], max_b[i])))
    segs = sorted(set(segs), key=lambda x: (-x[0], x[1]))
    print(segs)
    l, r = segs[0]
    ans = l * (2 * n - r + 1)
    for s in segs[1:]:
        l, rr = s
        if rr < r:
            ans += (r - rr) * l
        r = min(r, rr)
    print(ans)
