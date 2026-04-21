from math import gcd

t = int(input())
for _ in range(t):
    n, m, a, b = map(int, input().split())
    if gcd(a, n) == 1 and gcd(b, m) == 1 and gcd(n, m) <= 2:
        print("YES")
    else:
        print("NO")
