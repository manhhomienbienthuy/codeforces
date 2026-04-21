t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    print(max(a[1] - a[0], a[0]))
