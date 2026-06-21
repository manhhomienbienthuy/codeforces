t = int(input())
for _ in range(t):
    n, c = map(int, input().split())
    a = sorted(map(int, input().split()), reverse=True)
    k = 1
    for i in a:
        if i * k <= c:
            n -= 1
            k <<= 1
    print(n)
