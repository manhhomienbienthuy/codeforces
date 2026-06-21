t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = set(map(int, input().split()))
    a = [-1] + sorted(a)[:k - 1]
    for i in range(len(a) - 1):
        if a[i + 1] - a[i] > 1:
            print(a[i] + 1)
            break
    else:
        print(a[-1] + 1)
