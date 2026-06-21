t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()), reverse=True)
    b = list(map(int, input().split()))

    ans = 0
    s = 0
    for i in range(n):
        s += b[i]
        if s > n:
            break
        x = a[s - 1]
        ans = max(ans, x * (i + 1))

    print(ans)
