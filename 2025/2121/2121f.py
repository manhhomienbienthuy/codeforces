t = int(input())
for _ in range(t):
    n, s, x = map(int, input().split())
    a = list(map(int, input().split()))
    ans = 0
    before, after = {}, [0]
    pref = 0
    for v in a:
        if v > x:
            before.clear()
            after = [0]
            pref = 0
            continue
        if v == x:
            for k in after:
                before[k] = before.get(k, 0) + 1
            after = []
        pref += v
        after.append(pref)
        ans += before.get(pref - s, 0)

    print(ans)
