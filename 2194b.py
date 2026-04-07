t = int(input())
for _ in range(t):
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    b = [i // x * y for i in a]
    sm = sum(b)
    result = max(a)
    for i in range(n):
        result = max(result, sm - b[i] + a[i])
    print(result)
