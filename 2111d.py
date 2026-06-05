t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = sorted(map(int, input().split()))
    for i in range(n // 2):
        print(*[a[i], a[m - i - 1]] * 3)
        print(*[a[m - i - 1], a[i]] * 3)
    if n & 1:
        i = n // 2
        print(*[a[i], a[m - i - 1]] * 3)
