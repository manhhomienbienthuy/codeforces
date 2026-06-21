t  = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split())) + [-1]
    d = [a[i] * a[i + 1] < 0 for i in range(n)]
    print(sum(d))
    print(*(i + 1 for i in range(n - 1, -1, -1) if d[i]))
