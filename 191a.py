n = int(input())
f = [[0] * 26 for _ in range(26)]
for _ in range(n):
    s = input()
    length = len(s)
    l = ord(s[0]) - 97
    r = ord(s[-1]) - 97
    for i in range(26):
        if f[i][l]:
            f[i][r] = max(f[i][r], f[i][l] + length)
    f[l][r] = max(f[l][r], length)
print(max(f[i][i] for i in range(26)))
