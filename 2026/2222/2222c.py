t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    m = sorted(a)[n // 2]

    pref_sum = [0] * (n + 1)
    pref_m = [0] * (n + 1)
    for i in range(n):
        pref_sum[i + 1] = pref_sum[i] + ((a[i] > m) - (a[i] < m))
        pref_m[i + 1] = pref_m[i] + (a[i] == m)

    dp = [0] * n
    for r in range(n):
        for l in range(r + 1):
            if l > 0 and not dp[l - 1]:
                continue
            length = r - l + 1
            if length % 2 == 0:
                continue
            s = pref_sum[r + 1] - pref_sum[l]
            z = pref_m[r + 1] - pref_m[l]
            if z and abs(s) <= z:
                dp[r] = max(dp[r], (dp[l - 1] if l > 0 else 0) + 1)
    print(dp[n-1])
