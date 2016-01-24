#!/usr/bin/env python3

x = list(input())

if '4' < x[0] < '9':
    x[0] = str(9 - int(x[0]))

for i in range(1, len(x)):
    if x[i] > '4':
        x[i] = str(9 - int(x[i]))
print("".join(x))
