t = int(input())
for _ in range(t):
    n = int(input())
    c, p = [], []
    for i in range(n):
        ci, pi = map(int, input().split())
        c.append(ci)
        p.append(pi)

    results = c[-1]
    for i in range(n - 2, -1, -1):
        results = max(results, c[i] + results * (1 - p[i] / 100))
    print(results)
