t = int(input())
for _ in range(t):
    n, m, d = map(int, input().split())
    tower = 1 + d // m
    print(n // tower + (n % tower > 0))
