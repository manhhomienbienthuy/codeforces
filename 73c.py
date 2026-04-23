name, k = input().split()
k = int(k)
n = int(input())
mp = [[0] * 26 for _ in range(26)]
for _ in range(n):
    x, y, c = input().split()
    mp[ord(x) - 97][ord(y) - 97] = int(c)

sname = len(name)
MIN = -10**18
dp = [[MIN] * 26 for _ in range(k + 1)]

for z in range(26):
    c = 0 if z == ord(name[0]) - 97 else 1
    if c <= k:
        dp[c][z] = 0

for i in range(1, sname):
    ndp = [[MIN] * 26 for _ in range(k + 1)]
    for used in range(k + 1):
        for prev in range(26):
            if dp[used][prev] == MIN:
                continue
            for z in range(26):
                c = 0 if z == ord(name[i]) - 97 else 1
                if used + c <= k:
                    ndp[used + c][z] = max(
                        ndp[used + c][z],
                        dp[used][prev] + mp[prev][z]
                    )
    dp = ndp

print(max(max(dp[c]) for c in range(k + 1)))
