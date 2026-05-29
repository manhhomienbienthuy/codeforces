from math import gcd

t = int(input())
for _ in range(t):
    n = int(input())
    a = map(int, input().split())
    g = gcd(*a)
    if g <= 2:
        print(g + 1)
        continue
    for x in range(2, g // 2 + 1):
        if gcd(x, g) == 1:
            print(x)
            break
    else:
        print(g - 1)
