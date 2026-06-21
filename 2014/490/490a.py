#!/usr/bin/env python3

n = int(input())
t = [int(c) for c in input().split()]

teams = min(min(t.count(1), t.count(2)), t.count(3))
print(teams)
for i in range(teams):
    print(t.index(1) + 1, end=" ")
    t[t.index(1)] = 0
    print(t.index(2) + 1, end=" ")
    t[t.index(2)] = 0
    print(t.index(3) + 1)
    t[t.index(3)] = 0
