t = int(input())
for _ in range(t):
    s, m = map(int, input().split())
    ans = 0
    i = 1
    while True:
        x = (1 << i) - 1
        u, v = s & x, m & x
        if v == 0:
            if u:
                ans = -1
                break
            i += 1
            continue
        ans = max(ans, (u + v - 1) // v)
        if x >= s:
            break
        i += 1
    print(ans)
