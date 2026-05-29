t = int(input())
for _ in range(t):
    h, d = map(int, input().split())
    l, r = 0, d
    while l <= r:
        m = (l + r) // 2
        q, k = divmod(d, m + 1)
        s = (m + 1) * q * (q + 1) // 2 + k * (q + 1)
        if s < h + m:
            r = m - 1
        else:
            l = m + 1

    print(d + l)
