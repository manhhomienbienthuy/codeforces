def idx(c):
    return ord(c) - ord('a')

n, k = map(int, input().split())
s = input()
next_pos = [[-1] * k for _ in range(n + 2)]
for i in range(n - 1, -1, -1):
    for c in range(k):
        next_pos[i][c] = next_pos[i + 1][c]
    next_pos[i][idx(s[i])] = i

dp = [0] * (n + 2)
for i in range(n, -1, -1):
    ans = 10 ** 9
    for c in range(k):
        nxt = next_pos[i][c]
        if nxt == -1:
            ans = 1
            break
        ans = min(ans, dp[nxt + 1] + 1)
    dp[i] = ans

q = int(input())
for _ in range(q):
    t = input()
    i = 0
    for c in t:
        nxt = next_pos[i][idx(c)]
        if nxt == -1:
            print(0)
            break
        i = nxt + 1
    else:
        print(dp[i])
