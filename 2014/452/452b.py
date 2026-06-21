def dist(x, y):
    return (x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1])

n, m = map(int, input().split())
result = set((
    (n, m),
    (n, m-1),
    (n-1, m-1),
    (n-1, m),
    (n, 1),
    (n, 0),
    (n-1, 0),
    (n-1, 1),
    (1, 1),
    (1, 0),
    (0, 0),
    (0, 1),
    (1, m),
    (1, m-1),
    (0, m-1),
    (0, m),
))
result = list(filter(lambda x: n >= x[0] >= 0 and m >= x[1] >= 0, result))

tmp = -1
for i in result:
    for j in result:
        for k in result:
            for l in result:
                if i == j or i == k or i == l or j == k or j == l or k == l:
                    continue
                t = dist(i, j) + dist(j, k) + dist(k, l)
                if t > tmp:
                    tmp = t
                    a1, a2, a3, a4 = i, j, k, l

print(*a1)
print(*a2)
print(*a3)
print(*a4)
