#!/usr/bin/env python3

n = int(input())
x = list(map(int, input().split()))
for i in range(n):
    print(
        min(abs(x[i] - x[i-1]), abs(x[i] - x[(i+1) %n])),
        max(abs(x[i] - x[0]), abs(x[i] - x[-1]))
        )
