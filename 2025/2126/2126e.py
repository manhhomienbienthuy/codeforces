from math import gcd, lcm

t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    s = list(map(int, input().split()))
    a = [lcm(p[i], s[i]) for i in range(n)]
    gp = gs = 0
    for i in range(n):
        gp = gcd(gp, a[i])
        gs = gcd(gs, a[n - i - 1])
        if gp != p[i] or gs != s[n - i - 1]:
            print('NO')
            break
    else:
        print('YES')
