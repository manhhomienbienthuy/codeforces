t = int(input())
for _ in range(t):
    n = int(input())
    c = list(map(int, input().split()))
    if n == 1:
        print(c[0] if c[0] >= 3 else 0)
        continue

    d = c.count(1)
    e = sum(x // 2 - 1 for x in c if x >= 2) + (d == n - 1)
    print(sum(c) - d + min(d, e))
