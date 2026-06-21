t = int(input())
for _ in range(t):
    n = int(input())
    i = 10
    result = []
    while n // (i + 1) > 0:
        if n % (i + 1) == 0:
            result.append(n // (i + 1))
        i *= 10
    print(len(result))
    if result:
        print(*result[::-1])
