t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if a[0] == -1:
        a[0] = a[-1]
    if a[-1] == -1:
        a[-1] = a[0]
    for i in range(n):
        if a[i] == -1:
            a[i] = 0
    print(abs(a[-1] - a[0]))
    print(*a)
