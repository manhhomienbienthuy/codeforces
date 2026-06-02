t = int(input())
for _ in range(t):
    n, x, s = map(int, input().split())
    u = input()

    def calc(k):
        table = 0
        seated = 0
        ai = 0

        for c in u:
            if seated == x * s:
                break
            if c == 'I' or (c == 'A' and ai < k):
                if table < x:
                    table += 1
                    seated += 1
                    ai += c == 'A'
                continue
            if seated < table * s:
                seated += 1

        return seated

    l, r = 0, x
    while r - l > 3:
        m1 = (2 * l + r) // 3
        m2 = (l + 2 * r) // 3
        if calc(m1) < calc(m2):
            l = m1
        else:
            r = m2

    ans = 0
    for k in range(l, r + 1):
        ans = max(ans, calc(k))
    print(ans)
