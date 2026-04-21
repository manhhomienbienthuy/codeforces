t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    last_d = max_d = result = abs(a[1] - a[0])
    for i in range(1, n - 1):
        d = abs(a[i + 1] - a[i])
        result += d
        diff = d + last_d - abs(a[i + 1] - a[i - 1])
        if diff > max_d:
            max_d = diff
        last_d = d
    if last_d > max_d:
        max_d = last_d
    print(result - max_d)
