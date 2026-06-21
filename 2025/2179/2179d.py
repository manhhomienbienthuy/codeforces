t = int(input())
for _ in range(t):
    n = int(input())
    m = (1 << n) - 1
    result = [m]
    for i in range(1, n):
        cur = m >> i
        result.append(cur)
        for mask in range(1, 1 << (i - 1)):
            result.append(cur | (mask << (n - i + 1)))
    print(*result, *range(0, m, 2))
