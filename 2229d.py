t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    def check(k):
        d = 0
        is_bad = False
        for i in range(n):
            x = (a[i] >= k) + (b[i] >= k)
            if x == 2:
                d += 1
                is_bad = False
            elif x == 0 and not is_bad:
                d -= 1
                is_bad = True
        return d > 0

    l, r = 1, 2 * n
    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            l = mid + 1
        else:
            r = mid - 1
    print(r)
