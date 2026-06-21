from bisect import bisect_left

t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    m = a[n - 1]
    ans = 0
    for i in range(n - 2):
        r = i + 2
        for j in range(i + 1, n - 1):
            low = m - a[i] - a[j] + 1
            hi = a[i] + a[j] - 1
            while r < n and a[r] <= hi:
                r += 1
            l = bisect_left(a, low, j + 1)
            if l < r:
                ans += r - l
    print(ans)
