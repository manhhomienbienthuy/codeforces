t = int(input())
for _ in range(t):
    n, s, x = map(int, input().split())
    a = list(map(int, input().split()))

    def calc(k):
        res = 0
        pref = 0
        cnt = {0: 1}

        for v in a:
            if v > k:
                pref = 0
                cnt = {0: 1}
                continue
            pref += v
            res += cnt.get(pref - s, 0)
            cnt[pref] = cnt.get(pref, 0) + 1

        return res

    print(calc(x) - calc(x - 1))
