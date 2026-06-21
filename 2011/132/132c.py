#!/usr/bin/env python3

LMT = 105

def dfs(dre, pos, i, cn):
    if cn < 0:
        return 0

    if i >= len(work):
        return 0 if cn > 0 else abs(pos)

    if dp[dre][pos + 100][i][cn] != -1:
        return  dp[dre][pos + 100][i][cn]

    mv = 1 if dre else -1
    x = dfs(dre, pos + mv, i + 1, cn - (work[i] != "F"))
    y = dfs(not dre, pos, i + 1, cn - (work[i] != "T"))
    dp[dre][pos + 100][i][cn] = max(x, y)
    return dp[dre][pos + 100][i][cn]


work = input()
n = int(input())
dp = [[[[-1] * 52] * LMT] * (LMT << 1)] * 2
ans = 0

while n >= 0:
    ans = max(ans, dfs(True, 0, 0, n))
    n -= 2
print(ans)
