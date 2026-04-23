MOD = 998244353

def calc(L, R, r):
    """Count integers k in [L, R] such that k % 4 == r."""
    if L > R:
        return 0
    if L % 4 <= r:
        first = L + (r - L % 4)
    else:
        first = L + (4 - (L % 4 - r))
    if first > R:
        return 0
    return (R - first) // 4 + 1

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    cntA1 = calc(0, x-1, 1)
    cntB1 = calc(x, n, 1)
    result = cntA1 * cntB1
    if x >= 1:
        cntB3 = calc(x, n, 3)
        result += cntB3

        cntA3 = calc(1, x-1, 3)
        result += cntA3 * cntB3
    print(result % MOD)
