t = int(input())
for _ in range(t):
    s = list(input())
    n = len(s)
    ans = 0 + (s[0] == 'u') + (s[n - 1] == 'u')
    s[n - 1] = 's'
    i = 1
    while i < n - 1:
        if s[i] == 'u':
            ans += s[i + 1] == 'u'
            i += 2
        else:
            i += 1
    print(ans)
