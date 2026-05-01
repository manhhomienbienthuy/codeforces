t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0

    for mid in range(2 * n):
        l, r = mid, mid
        used = set()
        while l >= 0 and r < 2 * n and a[l] == a[r]:
            used.add(a[l])
            l -= 1
            r += 1
        mex = 0
        while mex in used:
            mex += 1
        ans = max(ans, mex)


    for mid in range(2 * n - 1):
        l, r = mid, mid + 1
        used = set()
        while l >= 0 and r < 2 * n and a[l] == a[r]:
            used.add(a[l])
            l -= 1
            r += 1
        mex = 0
        while mex in used:
            mex += 1
        ans = max(ans, mex)

    print(ans)
