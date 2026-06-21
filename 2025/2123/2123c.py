t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    result = ["0"] * n
    prefix = 10**6 + 1
    suffix = 0
    for i in range(n):
        if a[i] < prefix:
            result[i] = "1"
            prefix = a[i]
        if a[n - 1 - i] > suffix:
            result[n - 1 - i] = "1"
            suffix = a[n - 1 - i]
    print("".join(result))
