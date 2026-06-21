t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    cur = a[0]
    ans = 1
    for i in range(1, n):
        if a[i] > cur + 1:
            ans += 1
            cur = a[i]
    print(ans)
