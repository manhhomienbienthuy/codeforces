def calc(x, y, n):
    sx = bin(x)[2:]
    sy = bin(y)[2:]

    lx = len(sx)
    ly = len(sy)

    res = []
    for i in range(n):
        bx = sx[i % lx]
        by = sy[i % ly]
        res.append('1' if bx == '1' and by == '1' else '0')

    return ''.join(res)


t = int(input())
for _ in range(t):
    l, r, n = map(int, input().split())
    cand = []

    p = 1
    while p <= r:
        if p >= l:
            cand.append(p)
        p <<= 1

    ans = None
    for x in cand:
        for y in range(max(l, x + 1), min(r, x + 200) + 1):
            s = calc(x, y, n)
            if ans is None or s < ans:
                ans = s

        for y in range(max(l, x - 200), min(r, x - 1) + 1):
            s = calc(y, x, n)
            if ans is None or s < ans:
                ans = s

    if ans is None:
        for x in range(l, r + 1):
                for y in range(x + 1, r + 1):
                    s = calc(x, y, n)
                    if ans is None or s < ans:
                        ans = s

    print(ans)
