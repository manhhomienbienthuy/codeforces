#!/usr/bin/env python3

MOD = 1000000007
n = int(input())
print(1 if not n else ((pow(2, n-1, MOD) * (1 + pow(2, n, MOD))) % MOD))
