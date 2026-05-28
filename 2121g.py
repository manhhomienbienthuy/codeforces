t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    d = [0] * (n + 1)
    for i in range(n):
        d[i + 1] = d[i] + (s[i] == '1') - (s[i] != '1')
    d = sorted(d)

    ans = n * (n + 1) * (n + 2) // 6
    pref = 0
    for i in range(n + 1):
        ans += d[i] * i - pref
        pref += d[i]
    print(ans // 2)
