def calc(x, y, n):
    sx = bin(x)[2:]
    sy = bin(y)[2:]

    lx = len(sx)
    ly = len(sy)

    res = []
    for i in range(n):
        bx = sx[i % lx]
        by = sy[i % ly]
        res.append('1' if bx == by == '1' else '0')

    return ''.join(res)


t = int(input())
for _ in range(t):
    l, r, n = map(int, input().split())

    x = 1 << (r.bit_length() - 1)
    if x > l:
        y = max(l, x >> 1)
        print(calc(x, y, n))
        continue

    c = 0
    while l != r:
        c += 1
        l >>= 1
        r >>= 1
    print(calc(l << c, r << c, n))
