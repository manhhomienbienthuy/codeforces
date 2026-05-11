t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    pref = [0] * (n + 1)
    pref[1] = a[0]
    for i in range(2, n + 1):
        pref[i] = pref[i - 1] + abs(a[i - 1])
    suf = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        suf[i] = suf[i + 1] + a[i]
    ans = -10**18
    for i in range(n):
        ans = max(ans, pref[i] - suf[i + 1])
    print(ans)
