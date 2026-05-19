t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    if c <= 3 * b:
        q, r = divmod(a, 3)
        ans = q * c
        print(ans + min(r * b, c))
    else:
        print(a * b)
