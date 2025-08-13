t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    inc = sum(a[i] - b[i] if a[i] >= b[i] else 0 for i in range(n))
    print(inc + 1)
