#!/usr/bin/env python3

n, a, b, c = map(int, input().split())
max_ = 1
for i in range(n // a + 1):
    for j in range(n // b + 1):
        left = n - a * i - b * j
        if left % c == 0:
            k = left // c
            if i + j + k > max_:
                max_ = i + j + k
print(max_)
