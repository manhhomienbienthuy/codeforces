from math import ceil

n, m = map(int, input().split())
a = [dict() for _ in range(n)]
mp = dict()

for i in range(n):
    s = input()
    for c in s:
        mp[c] = mp.get(c, 0) + 1
        a[i][c] = a[i].get(c, 0) + 1
for i in range(n):
    mxx = 0
    for c in a[i]:
        if mp[c] != a[i][c]:
            mxx = max(mxx, ceil(a[i][c] / (mp[c] - a[i][c])))
        else:
            mxx = 10 ** 18
    print(max(m - mxx, -1), end=' ')
