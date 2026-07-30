# author: manhhomienbienthuy
# created: 2026-07-30T05:22:36+00:00
# https://codeforces.com/gym/106628/problem/M

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    C, Q = map(int, input().split())

    pool = []
    dirty = []

    for i in range(Q):
        data = input().split()
        if len(data) == 1:
            o, x = int(data[0]), 0
        else:
            o, x = map(int, data)

        if o == 1:
            if x in pool:
                pool.remove(x)
            pool.append(x)
            if len(pool) > C:
                if pool[0] in dirty:
                    dirty.remove(pool[0])
                del pool[0]
            continue
        if o == 2:
            if x not in dirty:
                dirty.append(x)
            if x in pool:
                pool.remove(x)
            pool.append(x)
            if len(pool) > C:
                if pool[0] in dirty:
                    dirty.remove(pool[0])
                del pool[0]
            continue
        if o == 3:
            print(len(dirty))
            dirty.clear()
            continue
        if o == 4:
            print(1 if x in pool else 0, 1 if x in dirty else 0)
            continue
