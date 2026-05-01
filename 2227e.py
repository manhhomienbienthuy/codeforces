t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print(0)
        continue

    suf = [n] * n
    suf[n - 1] = a[n - 1]
    done = False
    for i in range(n - 2, -1, -1):
        suf[i] = min(suf[i + 1], a[i])

    ans = sum(max(0, a[i] - suf[i + 1]) for i in range(n - 1))
    cur = suf[1]
    ext = tmp = a[0] >= suf[1]
    for i in range(2, n):
        if suf[i] != cur:
            cur = suf[i]
            ext = max(ext, tmp)
            tmp = a[i - 1] >= suf[i]
        else:
            tmp += a[i - 1] >= suf[i]
    print(ans + max(ext, tmp))
