t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    suf = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        suf[i] = max(suf[i + 1], a[i], b[i])
    kq = [0] * (n + 1)
    for i in range(n):
        kq[i + 1] = kq[i] + suf[i]

    ans = []
    for i in range(q):
        l, r = map(int, input().split())
        ans.append(kq[r] - kq[l - 1])
    print(*ans)
