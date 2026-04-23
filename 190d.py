n, k = map(int, input().split())
a = list(map(int, input().split()))

f = {}
bad = 0

l = 0
for r in range(n):
    f[a[r]] = f.get(a[r], 0) + 1

    while f[a[r]] >= k:
        f[a[l]] -= 1
        l += 1

    bad += r - l + 1
    print('bad', bad)

print(n * (n + 1) // 2 - bad)
