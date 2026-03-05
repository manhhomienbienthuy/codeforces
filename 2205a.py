t = int(input())
for _ in range(t):
    n = int(input())
    r = list(map(int, input().split()))
    m = max(r)
    i = r.index(m)
    r[0], r[i] = r[i], r[0]
    print(*r)
