t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    p = list(map(int, input().split()))

    x = a[p[0] - 1]
    b = [ai ^ x for ai in a]

    d = [0] * (n + 1)
    d[0] = b[0]
    for i in range(1, n):
        d[i] = b[i] ^ b[i - 1]
    d[n] = b[n - 1]

    segs = [sum(d[:p[0]])] + [sum(d[p[j] : p[j + 1]]) for j in range(k - 1)] + [sum(d[p[k - 1]:])]
    print(max(sum(segs) // 2, max(segs)))
