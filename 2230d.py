t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    dp = [n] * (n + 1)
    ans = 0
    for i in range(n - 1, -1, -1):
        if a[i] == b[i]:
            x = a[i]
            dp[x - 1] = dp[x]
        else:
            dp[a[i] - 1] = i
            dp[b[i] - 1] = i
        ans += dp[0] - i
    print(ans)
