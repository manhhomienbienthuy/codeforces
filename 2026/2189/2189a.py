t = int(input())
for _ in range(t):
    n, h, l = map(int, input().split())
    a = list(map(int, input().split()))
    x = y = 0
    if h > l:
        h, l = l, h
    for i in a:
        x += i <= h
        y += h < i <= l
    ans = min(x, y)
    ans += max(0, (x - ans) // 2)
    print(ans)
