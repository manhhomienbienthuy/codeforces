t = int(input())
for _ in range(t):
    n, m, r, c = map(int, input().split())
    f = n * m - (n - r + 1) * (m - c + 1)
    print(pow(2, f, 998244353))
