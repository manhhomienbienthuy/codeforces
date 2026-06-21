t = int(input())
for _ in range(t):
    n, c, k = map(int, input().split())
    a = sorted(map(int, input().split()), reverse=True)
    while a and a[-1] <= c:
        m = a.pop()
        s = min(c - m, k)
        c += m + s
        k -= s
    print(c)
