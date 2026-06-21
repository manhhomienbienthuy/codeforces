from math import sqrt

t = int(input())
for _ in range(t):
    n = int(input())
    result = 1
    for p in range(2, int(sqrt(n)) + 1):
        if not n % p:
            result *= p
            while not n % p:
                n //= p
    if n > 1:
        result *= n
    print(result)
