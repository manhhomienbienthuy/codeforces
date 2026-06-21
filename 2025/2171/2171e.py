from math import gcd

t = int(input())
for _ in range(t):
    n = int(input())
    p = list(range(n, 0, -1))
    i = 0
    if not n & 1:
        p[0], p[1] = p[1], p[0]
        i = 2
    while i < n - 7:
        g1 = gcd(p[i], p[i + 1])
        g2 = gcd(p[i + 1], p[i + 2])
        g3 = gcd(p[i], p[i + 2])
        if g1 == g2 == g3 == 1:
            for j in range(i + 3, n):
                if gcd(p[j], p[i]) > 1 or gcd(p[j], p[i + 1]) > 1:
                    p[i + 2], p[j] = p[j], p[i + 2]
                    break
        i += 1
    print(*p)
