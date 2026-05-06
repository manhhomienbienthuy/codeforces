t = int(input())
for _ in range(t):
    n, h, k = map(int, input().split())
    a = list(map(int, input().split()))
    s = sum(a)
    q, r = divmod(h, s)
    ans = q * (n + k)
    if not r:
        print(ans - k)
        continue

    suf = [0] * (n + 1)
    suf[n - 1] = a[n - 1]
    for i in range(n - 2, -1, -1):
        suf[i] = max(suf[i + 1], a[i])
    s = 0
    pref = 10**18
    for i in range(n):
        s += a[i]
        pref = min(pref, a[i])
        x = s - pref + suf[i + 1]
        if x >= r or s >= r:
            print(ans + i + 1)
            break
    else:
        print(ans + n)
