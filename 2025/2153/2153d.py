t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    ans = 10 ** 18
    for start in (0, 1, 2):
        dp = [0] * n
        dp[0] = abs(a[start] - a[(start - 1) % n])
        s = sorted([a[(start - 2) % n], a[(start - 1) % n], a[start]])
        dp[0] = min(dp[0], s[2] - s[0])

        dp[1] = abs(a[(start + 1) % n] - a[start])
        s = sorted([a[(start + 1) % n], a[start], a[(start - 1) % n]])
        dp[1] = min(dp[1], s[2] - s[0])

        for i in range(2, n):
            cost2 = dp[i - 2] + abs(a[(start + i) % n] - a[(start + i - 1) % n])
            s = sorted([a[(start + i - 2) % n], a[(start + i - 1) % n], a[(start + i) % n]])
            cost3 = dp[i - 3] + s[2] - s[0]
            dp[i] = min(cost2, cost3)
        ans = min(ans, dp[n - 1])

    print(ans)
