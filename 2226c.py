t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))

    def check(k):
        build = set()
        need = 0
        for x in a:
            if x < k and x not in build:
                build.add(x)
                while need in build:
                    need += 1
            elif x >= 2 * need + 1:
                build.add(need)
                while need in build:
                    need += 1
        return need >= k

    l, r = 0, n + 1
    while l + 1 < r:
        mid = (l + r) // 2
        if check(mid):
            l = mid
        else:
            r = mid

    print(l)
