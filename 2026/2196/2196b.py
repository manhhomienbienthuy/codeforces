from math import isqrt

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = isqrt(n)

    ans = 0
    for i in range(n):
        x = a[i]
        if x >= n:
            continue
        if x > b:
            for k in range(1, (n - i - 1) // x + 1):
                j = i + x * k
                ans += a[j] == k
            for k in range(1, i // x + 1):
                j = i - x * k
                ans += a[j] == k
        else:
            for k in range(1, b + 1):
                j = i + x * k
                if j >= n:
                    break
                ans += a[j] == k
    print(ans)
