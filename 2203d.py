t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = sorted(map(int, input().split()))
    b = list(map(int, input().split()))
    mm = max(b)

    p = [0] * (mm + 1)
    for i in a:
        if i > mm:
            break
        p[i] += 1

    c = [0] * (mm + 1)
    for i in range(1, mm + 1):
        if not p[i]:
            continue
        for j in range(i, mm + 1, i):
            c[j] += p[i]

    A = B = both = 0
    for y in b:
        if not c[y]:
            B += 1
        elif c[y] == n:
            A += 1
        else:
            both += 1

    print('Alice' if A + (both & 1) > B else 'Bob')
