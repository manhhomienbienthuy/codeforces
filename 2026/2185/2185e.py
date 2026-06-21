from bisect import bisect_left
from collections import defaultdict

t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = sorted(map(int, input().split()))
    s = input()
    steps = defaultdict(lambda: k + 1)
    x = 0
    for i in range(k):
        if s[i] == 'R':
            x += 1
        else:
            x -= 1
        steps[x] = min(steps[x], i + 1)
    dead = [0] * (k + 2)
    for x in a:
        i = bisect_left(b, x)
        t = k + 1
        if i < m:
            t = min(t, steps[b[i] - x])
        if i > 0:
            t = min(t, steps[b[i - 1] - x])
        dead[t] += 1
    for i in range(1, k + 1):
        print(n - dead[i], end=' ')
        n -= dead[i]
    print()
