t = int(input())
for _ in range(t):
    n, m = map(int,input().split())
    a = list(map(int,input().split()))
    if a == list(range(a[0], a[0] + m)):
        print(n - a[-1] + 1)
    else:
        print(1)
