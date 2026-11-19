# author: manhhomienbienthuy
# created: 2026-11-19T00:59:22+00:00
# https://codeforces.com/gym/106826/problem/A

import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())

    files = []
    base = ''

    for _ in range(n):
        b, ext = input().strip().split('.')
        if ext == 'EXE':
            base = b
        else:
            files.append((b, ext))

    if n == 1:
        print(base + '.EXE')
        continue

    mn = min(files)

    for add in range(10):
        if (base, 'EXE') < mn:
            print(base + '.EXE')
            break
        base = ('A' + base)[:8]
    else:
        print('IMPOSSIBLE')
