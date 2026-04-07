t = int(input())
for _ in range(t):
    n, w = map(int, input().split())
    print(n // w * (w - 1) + n % w)
