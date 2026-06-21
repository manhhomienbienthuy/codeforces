t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if all(a[i] <= b[i] for i in range(n)):
        print(0)
        continue
    c = sorted(a)
    if any(c[i] > b[i] for i in range(n)):
        print(-1)
        continue

    ans = 0
    for i in range(n):
        if a[i] > b[i]:
            j = i + 1
            while a[j] > b[i]:
                j += 1
            ans += j - i
            a = a[:i] + [a[j]] + a[i:j] + a[j + 1:]
    print(ans)
