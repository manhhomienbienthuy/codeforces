t = int(input())
for _ in range(t):
    x = list(map(int, input()))
    x[0] -= 1
    x = sorted(x)
    s = sum(x)
    results = 0
    while s > 8:
        s -= x.pop()
        results += 1
    print(results)
