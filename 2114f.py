from math import gcd

def calc(n, k):
    if n == 1:
        return 0
    if n <= k:
        return 1
    dp = [-1] * (n + 1)
    f = set()
    for i in range(2, k + 1):
        if n % i == 0:
            dp[i] = 1
            f.add(i)
    if not f:
        return -1

    cur = f.copy()
    while n not in cur:
        nxt = set()
        for i in f:
            for j in cur:
                z = i * j
                if z > n or z <= k or n % z:
                    continue
                nxt.add(z)
                if dp[z] == -1:
                    dp[z] = dp[j] + 1
                else:
                    dp[z] = min(dp[z], dp[j] + 1)
        if not nxt:
            return -1
        cur = nxt
    return dp[n]

t = int(input())
for _ in range(t):
    x, y, k = map(int, input().split())
    g = gcd(x, y)
    m, n = x // g, y // g
    s1 = calc(m, k)
    s2 = calc(n, k)
    if s1 < 0 or s2 < 0:
        print(-1)
    else:
        print(s1 + s2)
