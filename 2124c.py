import math

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    result = set()
    for i in range(n - 1):
        if a[i + 1] % a[i]:
            s = a[i] // math.gcd(a[i], a[i + 1])
            result.add(s)
    print(math.lcm(*result))
