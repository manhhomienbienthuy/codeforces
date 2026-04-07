t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    result = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            result = max(result, a[i] ^ a[j])
    print(result)
