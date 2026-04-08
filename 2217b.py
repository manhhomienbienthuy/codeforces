t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    p = int(input())
    x = a[p - 1]
    b = [ai ^ x for ai in a]

    fl = 0
    if p - 1 > 0:
        if b[0] != 0:
            fl += 1
        for i in range(p - 2):
            if b[i] != b[i + 1]:
                fl += 1

    fr = 0
    if p < n:
        if b[n - 1] != 0:
            fr += 1
        for i in range(p, n - 1):
            if b[i] != b[i + 1]:
                fr += 1

    ans = max(fl, fr)
    if ans % 2 == 1:
        ans += 1
    print(ans)
