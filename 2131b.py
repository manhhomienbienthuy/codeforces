t = int(input())
for _ in range(t):
    n = int(input())
    result = [3 if i % 2 else -1 for i in range(n)]
    if result[-1] > 0:
        result[-1] = 2
    print(*result)
