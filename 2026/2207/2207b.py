t = int(input())
for _ in range(t):
    n, m, l = map(int, input().split())
    a = list(map(int, input().split()))
    d = [0] * min(m, n + 1)
    for i in range(1, l + 1):
        d[-1] += 1
        d = sorted(d, reverse=True)

        if(n > 0 and a[0] == i):
            d = d[1:] + [0]
            if n < m:
                d.pop()
            a = a[1:]
            n -= 1
    print(d[0])
