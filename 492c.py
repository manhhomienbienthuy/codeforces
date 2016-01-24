#!/usr/bin/env python3

n, r, avg = map(int, input().split())
scores, essays = [], []
for _ in range(n):
    a, b = map(int, input().split())
    scores.append(a)
    essays.append(b)

now = sum(scores)
ineed = n * avg
essay_cnt = 0

while now < ineed:
    pref = sorted(range(n), key=essays.__getitem__)
    for i in pref:
        a, b = scores[i], essays[i]
        delta = min(ineed - now, r - a)
        essay_cnt += b * delta
        now += delta

print(essay_cnt)
