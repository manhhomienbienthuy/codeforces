t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    suf = 0
    ans = 0
    for i in range(n - 1, -1, -1):
        suf += a[i]
        ans += suf > 0
        if suf < 0:
            suf = 0
    print(ans)
