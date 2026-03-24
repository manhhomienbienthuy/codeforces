t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = []
    for i in range(n):
        less = greater = 0
        for j in range(i + 1, n):
            if a[j] < a[i]:
                less += 1
            elif a[j] > a[i]:
                greater += 1
        ans.append(max(less, greater))
    print(*ans)
