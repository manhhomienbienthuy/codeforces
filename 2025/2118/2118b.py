t = int(input())
for _ in range(t):
    n = int(input())
    result = []
    for i in range(1, n):
        if i > 1:
            result.append((i, 1, i))
        if i < n - 1:
            result.append((i, i + 1, n))
    result.append((n, 1, n))
    print(len(result))
    for r in result:
        print(*r)
