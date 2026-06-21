t = int(input())
for _ in range(t):
    n = int(input())
    s = list(map(int, input()))
    a = list(map(int, input().split()))
    c = list(map(int, input().split()))

    if s[0] and a[0] != c[0]:
        print('NO')
        continue

    ok = True
    b = [0] * n
    v = [False] * n
    v[0] = True
    a[0] = b[0] = c[0]

    for i in range(n - 1, 0, -1):
        if c[i] < c[i - 1]:
            print('NO')
            ok = False
            break
        if c[i] > c[i - 1]:
            v[i] = True
            b[i] = c[i]

        if v[i] and s[i] and not v[i - 1]:
            v[i - 1] = True
            b[i - 1] = b[i] - a[i]
            if b[i - 1] > c[i - 1]:
                print('NO')
                ok = False
                break
    if not ok:
        continue

    for i in range(1, n):
        if v[i]:
            x = b[i] - b[i - 1]
            if not s[i]:
                a[i] = x
            else:
                if a[i] != x:
                    print('NO')
                    ok = False
                    break
        else:
            if s[i]:
                v[i] = True
                b[i] = b[i - 1] + a[i]
                if b[i] > c[i]:
                    print('NO')
                    ok = False
                    break
            else:
                b[i] = -10**12
                a[i] = b[i] - b[i - 1]
    if ok:
        print('YES')
        print(*a)
