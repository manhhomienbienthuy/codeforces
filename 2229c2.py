t  = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split())) + [-1]
    pref = [0] * (n + 1)
    suf = [0] * (n + 1)
    for i in range(n):
        pref[i + 1] = pref[i] + abs(a[i])
        suf[n - i - 1] = suf[n - i] + a[n - i - 1]
    m = suf[0]
    idx = -1
    for i in range(n):
        if a[i] < 0:
            continue
        x = pref[i] + suf[i + 1] - a[i]
        if x > m:
            m = x
            idx = i
    if idx == -1:
        print(0)
        continue
    a[idx] = -1
    d = [a[i] * a[i + 1] < 0 for i in range(idx)]
    print(1 + sum(d))
    print(*(i + 1 for i in range(idx - 1, -1, -1) if d[i]), idx + 1)
