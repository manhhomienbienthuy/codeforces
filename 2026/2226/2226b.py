from math import gcd

t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    print(sum(abs(p[i] - p[i + 1]) == gcd(p[i], p[i + 1]) for i in range(n - 1)))
