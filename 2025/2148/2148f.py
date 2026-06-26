t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    for i in range(n):
        x = list(map(int, input().split()[1:]))
        a.append(x)
    ans = []
    while a:
        m = min(a)
        ans += m
        l = len(m)
        a = [x[l:] for x in a if len(x) > l]
    print(*ans)
