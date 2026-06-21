t = int(input())
for _ in range(t):
    n = int(input())
    a = dict()
    for i in range(n):
        for x in map(int, input().split()):
            a[x] = a.get(x, 0) + 1
    print('NO' if max(a.values()) > (n - 1) * n else 'YES')
