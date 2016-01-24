#!/usr/bin/env python3


n = int(input())

res = 1
k = 2

def is_prime(x):
    for i in range(k, int(x ** 0.5) + 1):
        if x % i == 0:
            return i
    return -1

while n > 1:
    k = is_prime(n)
    if k == -1:
        res *= n
        n = 1
    else:
        res *= k
        while n % k == 0:
            n //= k
print(res)
