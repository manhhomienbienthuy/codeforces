t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = [0] * (n + 1)
    for i in input().split():
        a[int(i)] += 1
    print(max(a[k], a[:k].count(0)))
