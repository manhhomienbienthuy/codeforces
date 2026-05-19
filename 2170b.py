t = int(input())
for _ in range(t):
    n = int(input())
    b = sorted(map(int, input().split()))
    s = sum(x - 1 for x in b if x > 1)
    print(n - b.count(0) - max(0, n - s - 1))
