from math import isqrt

def factor(n):
    if n < 4:
        return n
    for i in range(2, isqrt(n) + 1):
        if n % i == 0:
            while n % i == 0:
                n //= i
            if n == 1:
                return i
            return -1
    return n

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if a == sorted(a):
        print('Bob')
        continue
    f = [factor(a[i]) for i in range(n)]
    if -1 in f or f != sorted(f):
        print('Alice')
    else:
        print('Bob')
