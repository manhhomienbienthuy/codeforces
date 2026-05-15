def calc(a):
    minx, miny = 10**18, 10**18
    maxx, maxy = -10**18, -10**18
    for x in a:
        minx, miny = min(minx, x[0]), min(miny, x[1])
        maxx, maxy = max(maxx, x[0]), max(maxy, x[1])
    r, c = maxx - minx + 1, maxy - miny + 1
    ans = r * c
    if ans == len(a):
        ans += min(r, c)
    return ans

t = int(input())
for _ in range(t):
    n = int(input())
    monsters = []
    for i in range(n):
        x, y = map(int, input().split())
        monsters.append((x, y))
    if n < 3:
        print(n)
        continue

    def calc(a):
        minx, miny = 10**18, 10**18
        maxx, maxy = -10**18, -10**18
        for x in a:
            minx, miny = min(minx, x[0]), min(miny, x[1])
            maxx, maxy = max(maxx, x[0]), max(maxy, x[1])
        r, c = maxx - minx + 1, maxy - miny + 1
        res = r * c
        if res == n - 1:
            res += min(r, c)
        return res

    monstersx = sorted(monsters)
    monstersy = sorted(monsters, key=lambda x: (x[1], x[0]))
    ans = min(calc(monstersx[1:]), calc(monstersx[:-1]), calc(monstersy[1:]), calc(monstersy[:-1]))
    print(ans)
