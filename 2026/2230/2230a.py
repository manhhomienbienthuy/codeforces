t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    q, r = divmod(n, 3)
    print(q * min(3 * a, b) + min(r * a, b))
