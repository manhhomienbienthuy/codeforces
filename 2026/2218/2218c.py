t = int(input())
for _ in range(t):
    n = int(input())
    a = range(n + 1, 3 * n + 1)
    for i in range(n):
        print(i + 1, a[2 * i], a[2 * i + 1], end=" ")
    print()
