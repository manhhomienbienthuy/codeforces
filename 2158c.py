t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    x = y = ans = -10**9
    for i in range(n):
        x = max(x + a[i], a[i])
        if k & 1:
            y = max(y + a[i], x + b[i])
        ans = max(ans, x, y)
    print(ans)
