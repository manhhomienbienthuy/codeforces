from math import lcm

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = []
    b = []
    c = []
    for i in range(n):
        z, u, v = map(int, input().split())
        a.append(z)
        b.append(u)
        c.append(v)

    f = 0
    for i in range(n):
        f += (b[i] - 1) * a[i]
    if f >= x:
        print(0)
        continue
    x -= f
    m = max(a[i] * b[i] - c[i] for i in range(n))
    if m <= 0:
        print(-1)
        continue
    print(x // m + (x % m > 0))
