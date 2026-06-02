t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = [0] * n
    s = 0
    cur = a[0]
    for i in range(n):
        s += a[i]
        ans[i] = cur = min(cur, s // (i + 1))
    print(*ans)
