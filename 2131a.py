t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    inc = sum(max(a[i] - b[i], 0) for i in range(n))
    print(inc + 1)
