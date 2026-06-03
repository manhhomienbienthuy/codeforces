from math import gcd

t = int(input())
for _ in range(t):
    l, a, b = map(int, input().split())
    s = gcd(l, b)
    print(l - s + a % s)
