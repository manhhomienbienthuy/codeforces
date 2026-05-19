t = int(input())
for _ in range(t):
    n = int(input())
    c = list(map(int, input().split()))
    if n == 1:
        print(c[0] if c[0] >= 3 else 0)
        continue

    d = c.count(1)
    ans = sum(c) - d
    if d == n - 1:
        ans += min(d, ans // 2)
    elif ans:
        e = sum(x // 2 - 1 for x in c if x >= 4)
        ans += min(d, e)
    print(ans)
