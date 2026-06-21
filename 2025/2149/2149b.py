t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    print(max(a[i+1] - a[i] for i in range(0, n - 1, 2)))
