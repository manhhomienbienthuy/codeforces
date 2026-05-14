t = int(input())
for _ in range(t):
    n, m, q = map(int, input().split())
    a = sorted(map(int, input().split()), reverse=True)
    b = sorted(map(int, input().split()), reverse=True)
    sa = [0] * (n + 1)
    for i in range(n):
        sa[i + 1] = sa[i] + a[i]
    sb = [0] * (m + 1)
    for i in range(m):
        sb[i + 1] = sb[i] + b[i]
    for i in range(q):
        x, y, z = map(int, input().split())
        l = max(0, z - y)
        r = min(n, x, z)
        if l > r:
            print(0)
            continue
        while r - l > 3:
            m1 = l + (r - l) // 3
            m2 = r - (r - l) // 3
            f1 = sa[m1] + sb[z - m1]
            f2 = sa[m2] + sb[z - m2]
            if f1 < f2:
                l = m1
            else:
                r = m2

        ans = 0
        for j in range(l, r + 1):
            ans = max(ans, sa[j] + sb[z-j])
        print(ans)
