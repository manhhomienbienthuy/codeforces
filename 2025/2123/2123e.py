t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0] * (n + 1)
    for x in a:
        cnt[x] += 1
    d = [0] * (n + 2)
    for m in range(n + 1):
        if m > 0 and cnt[m - 1] == 0:
            break
        l = cnt[m]
        r = n - m
        if l <= r:
            d[l] += 1
            d[r + 1] -= 1
    ans = [0] * (n + 1)
    for i in range(n + 1):
        ans[i] = ans[i - 1] + d[i]
    print(*ans)
