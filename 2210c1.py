from math import lcm, gcd

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    g = [1] + [gcd(a[i], a[i + 1]) for i in range(n - 1)] + [1]
    result = 0
    for i in range(n):
        c = lcm(g[i], g[i + 1])
        result += c < b[i]
    print(result)
