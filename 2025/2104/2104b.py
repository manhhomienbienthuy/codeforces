t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s, m = sum(a), 0
    res = []
    for i in range(n):
        s -= a[i]
        m = max(m, a[i])
        res.append(s + m)
    print(' '.join(map(str, res[::-1])))
