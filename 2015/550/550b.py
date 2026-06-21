#!/usr/bin/env python3

import itertools

n, l, r, x = map(int, input().split())
c = list(map(int, input().split()))
cnt = 0

for i in range(2, n + 1):
    combinations = itertools.combinations(c, i)
    for comb in combinations:
        max_ = 0
        min_ = 10**6
        sum_ = 0
        for co in comb:
            sum_ += co
            if co > max_:
                max_ = co
            if co < min_:
                min_ = co
        cnt += 1 if (l <= sum_ <= r and max_ - min_ >= x) else 0
print(cnt)
