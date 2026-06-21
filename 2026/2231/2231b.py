t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    pref = [0] * n
    for i in range(n):
        pref[i] = max(pref[i - 1], a[i])
    d = max(pref[i] - a[i] for i in range(n))
    for i in range(1, n):
        if a[i] < a[i - 1]:
            a[i] += d
        if a[i] < a[i - 1]:
            print('NO')
            break
    else:
        print('YES')
