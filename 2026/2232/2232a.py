t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    ans = n
    cur, cnt = 0, 1
    for i in range(n):
        if a[i] == cur:
            cnt += 1
        else:
            cur, cnt = a[i], 1
        ans = min(ans, max(n - i - 1, i + 1 - cnt))
    print(ans)
