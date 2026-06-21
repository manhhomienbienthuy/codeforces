MOD = 998244353

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    cntA1 = (x - 2) // 4 + 1
    cntB1 = (n - 1) // 4 + 1 - cntA1
    result = cntA1 * cntB1 % MOD
    cntA3 = x // 4
    cntB3 = (n - 3) // 4 + 1 - cntA3
    result += (1 + cntA3) * cntB3 % MOD
    print(result % MOD)
