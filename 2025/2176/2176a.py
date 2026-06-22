t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    m = a[0]
    ans = 0
    for i in range(1, n):
        if a[i] < m:
            ans += 1
        else:
            m = a[i]
    print(ans)
