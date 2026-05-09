t = int(input())
for _ in range(t):
    n, h = map(int, input().split())
    a = list(map(int, input().split()))
    sa = sorted(set(x for x in a if x >= a[h - 1]))
    w = 1
    for i in range(len(sa) - 1):
        t1 = sa[i] + 1 - w
        t2 = sa[i + 1] - sa[i]
        if t1 < t2:
            print('NO')
            break
        w += t2
    else:
        print('YES')
