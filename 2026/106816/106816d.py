# author: manhhomienbienthuy
# created: 2026-11-10T03:47:05+00:00
# https://codeforces.com/gym/106816/problem/4

import sys
from math import isqrt
input = sys.stdin.readline

n = int(input())
a = map(int, input().split())

s = 1 + sum(x * x for x in a)
print(isqrt(s))
