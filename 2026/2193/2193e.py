t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(set(map(int, input().split())))

    dp = [10**18] * (n + 1)
    for x in a:
        dp[x] = 1

    for x in a:
        for i in range(2 * x, n + 1, x):
            dp[i] = min(dp[i], dp[i // x] + 1)

    print(*(-1 if dp[i] == 10**18 else dp[i] for i in range(1, n + 1)))
