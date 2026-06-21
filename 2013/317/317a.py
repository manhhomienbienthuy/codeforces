#!/usr/bin/env python3

x, y, m = map(int, input().split())
result = 0
if x <= 0 and y <= 0:
    if x < m and y < m:
        print(-1)
    else:
        print(0)
    exit()

while x < m and y < m:
    x, y = (y, x) if x > y else (x, y)
    tmp = 1 + (y - x) // y
    result += tmp
    x = x + tmp * y
print(result)
