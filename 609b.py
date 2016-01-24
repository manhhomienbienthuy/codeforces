#!/usr/bin/env python3

n, m = map(int, input().split())
a = list(map(int, input().split()))

genres = []
for i in range(m):
    genres.append(a.count(i + 1))

result = 0
for i in range(m - 1):
    for j in range(i + 1, m):
        result += genres[i] * genres[j]

print(result)
