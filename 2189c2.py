t = int(input())
for _ in range(t):
    n = int(input())
    p = [1] * n
    for i in range(n - 2, 0, -1):
        p[i] = 1 ^ (i + 1)
    p[0] = n - (n & 1)
    if n & 1:
        print(*p)
    else:
        for i in range(1, n - 1, 2):
            if i - 1 < (n ^ (i + 1)) < n:
                p[0], p[i] = p[i], p[0]
                print(*p)
                break
        else:
            print(-1)
