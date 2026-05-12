t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    ans = 0
    l = r = k
    while True:
        if l <= n <= r:
            print(ans)
            break
        if n < l <= r:
            print(-1)
            break
        ans += 1
        l, r = 2 * l - 1, 2 * r + 1
