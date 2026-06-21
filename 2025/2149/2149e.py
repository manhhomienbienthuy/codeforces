t = int(input())
for _ in range(t):
    n, k, l, r = map(int, input().split())
    a = list(map(int, input().split()))

    v = list(set(a))
    mp = {v:i for i,v in enumerate(v)}
    a = [mp[x] for x in a]
    m = len(v)

    cnt1 = [0] * m
    cnt2 = [0] * m
    l1 = l2 = 0
    d1 = d2 = 0
    ans = 0

    for i in range(n):
        d1 += cnt1[a[i]] == 0
        cnt1[a[i]] += 1
        d2 += cnt2[a[i]] == 0
        cnt2[a[i]] += 1

        while d1 > k:
            cnt1[a[l1]] -= 1
            if cnt1[a[l1]] == 0:
                d1 -= 1
            l1 += 1

        while d2 > k - 1:
            cnt2[a[l2]] -= 1
            if cnt2[a[l2]] == 0:
                d2 -= 1
            l2 += 1

        lo = max(l1, i - r + 1)
        hi = min(l2 - 1, i - l + 1)

        if lo <= hi:
            ans += (hi - lo + 1)

    print(ans)
