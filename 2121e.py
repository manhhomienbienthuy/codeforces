t = int(input())
for _ in range(t):
    l, r = input().split()
    l = list(map(int, l))
    r = list(map(int, r))
    n = len(l)
    x = [0] * n
    d = 0
    ans = 0
    for i in range(n):
        d = d * 10 + r[i] - l[i]
        if d == 0:
            ans += 2
        elif d == 1:
            ans += 1
    print(ans)
