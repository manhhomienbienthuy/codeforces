n, m = map(int, input().split())
a = [dict() for _ in range(n)]
mp = dict()

for i in range(n):
    s = input()
    for c in s:
        mp[c] = mp.get(c, 0) + 1
        a[i][c] = a[i].get(c, 0) + 1

for i in range(n):
    res = m
    for c in a[i]:
        if mp[c] > a[i][c]:
            res = min(res, max(-1, m - (mp[c] - 1) // (mp[c] - a[i][c])))
        else:
            print(-1, end= ' ')
            break
    else:
        print(res, end=' ')
