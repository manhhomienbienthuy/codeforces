#!/usr/bin/env python
import sys

a = [[0, 0, 0],  [0, 0, 0], [0, 0, 0]]
b = [[0, 0, 0, 0, 0],  [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
c = [[0, 0, 0, 0, 0],  [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]

for i in range(3):
    a[i] = raw_input().split(" ")

for i in [1, 2, 3]:
    for j in [1, 2, 3]:
        b[i][j] = int(a[i-1][j-1])

for i in [1, 2, 3]:
    for j in [1, 2, 3]:
        c[i][j] = (b[i][j] + b[i-1][j] + b[i+1][j] + b[i][j-1] + b[i][j+1] + 1) % 2

for i in [1, 2, 3]:
    for  j in [1, 2, 3]:
        sys.stdout.write(chr(c[i][j]+48));
    print
