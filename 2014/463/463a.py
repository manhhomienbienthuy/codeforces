n, s = map(int, input().split())

x, y = [], []
for i in range(n):
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)

max_candy = -1
for i in range(n):
    if y[i]:
        if s > x[i]:
            max_candy = max(max_candy, 100 - y[i])
    else:
        if s >= x[i]:
            max_candy = max(max_candy, 0)
print(max_candy)
