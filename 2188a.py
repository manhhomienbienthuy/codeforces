t = int(input())
for _ in range(t):
    n = int(input())
    p = [0] * n
    for i in range(n // 2):
        p[n - 1 - 2*i] = i+ 1
        p[n - 2 - 2* i] = n - i
    if n & 1:
        p[0] = (n + 1) // 2
    print(*p)
