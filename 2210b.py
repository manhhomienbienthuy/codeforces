t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    result = 0
    for i in range(1, n + 1):
        if p[i - 1] <= i:
            result += 1
    print(result)
