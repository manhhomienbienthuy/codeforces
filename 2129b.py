t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    result = 0
    for i in range(n):
        left = sum(p[j] > p[i] for j in range(i))
        right = sum(p[j] > p[i] for j in range(i + 1, n))
        result += min(left, right)
    print(result)
