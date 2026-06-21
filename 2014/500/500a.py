#!/usr/bin/env python3

n, t = map(int, input().split())
a = list(map(int, input().split()))
current = 1
while current < t:
    current += a[current - 1]
print("YES" if current == t else "NO")
