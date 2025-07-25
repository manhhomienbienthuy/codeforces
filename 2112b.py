t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n - 1):
        if abs(a[i] - a[i + 1]) <= 1:
            print(0)
            break
    else:
        b = sorted(a)
        print(-1 if a == b or a == b[::-1] else 1)
