t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    d = a[0] - a[1]
    for i in range(1, n):
        if d != a[i - 1] - a[i]:
            print('NO')
            break
    else:
        x = min(a[0], a[n - 1]) - abs(d)
        if x >= 0 and x % (n + 1) == 0:
            print('YES')
        else:
            print('NO')
