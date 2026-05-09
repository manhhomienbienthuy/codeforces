t = int(input())
for _ in range(t):
    n = int(input())
    p = [1] * n
    for i in range(n - 2, 0, -1):
        p[i] = 1 ^ (i + 1)
    p[0] = n - (n & 1)
    print(*p)
