#!/usr/bin/env python3

n, x0, y0 = map(int, input().split())

stormtroopers = [list(map(int, input().split())) for _ in range(n)]

diff = [(x - x0, y - y0) for x, y in stormtroopers]

diff_set = set()
for x, y in diff:
    try:
        tmp = x / y
        diff_set.add(tmp)
    except ZeroDivisionError:
        diff_set.add("ZERO")
print(len(diff_set))
