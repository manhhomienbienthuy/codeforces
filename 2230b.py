t = int(input())
for _ in range(t):
    s = input()
    n = len(s)
    pref = [0] * n
    suf = [0] * (n + 1)
    for i in range(n):
        pref[i] = pref[i - 1] + (s[i] == '2')
        suf[n - i - 1] = suf[n - i] + (s[n - i - 1] in '13')
    print(n - max(pref[i] + suf[i] for i in range(n)))
