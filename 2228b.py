t = int(input())
for _ in range(t):
    n, x1, x2, k = map(int, input().split())
    if n < 4:
        print(1)
        continue
    d = abs(x2 - x1)
    d = min(d, n - d)
    print(d + k)
