t = int(input())
for _ in range(t):
    n, m, h = map(int, input().split())
    a = list(map(int, input().split()))
    b = [0] * n
    last = [0] * n
    reset = -1
    for i in range(m):
        bi, ci = map(int, input().split())
        bi -= 1
        if last[bi] <= reset:
            b[bi] = ci
        else:
            b[bi] += ci
        last[bi] = i
        if a[bi] + b[bi] > h:
            reset = i
    for i in range(n):
        if last[i] <= reset:
            print(a[i], end=' ')
        else:
            print(a[i] + b[i], end=' ')
    print()
