t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(1, n):
        if a[i] == a[i - 1] or a[i] + a[i - 1] == 7:
            ans += 1
            a[i] = 0
    print(ans)
