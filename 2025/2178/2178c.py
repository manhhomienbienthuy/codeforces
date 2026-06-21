t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    suf = sum(a) - a[0]
    ans = -suf
    pref = a[0]
    for i in range(1, n):
        suf -= a[i]
        ans = max(ans, pref - suf)
        if i == 0:
            pref = a[0]
        else:
            pref += abs(a[i])
    print(ans)
