t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    q = sorted(map(int, input().split()))
    r = sorted(map(int, input().split()), reverse=True)

    ans = 0
    i = -1
    for x in q:
        i += 1
        while i < n and x * (r[i] + 1) + r[i] > k:
            i += 1
        ans += i < n
        if i >= n - 1:
            break
    print(ans)
