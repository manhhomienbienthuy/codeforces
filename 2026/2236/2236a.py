t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    m = max(a)
    k = max(m - x for x in a)
    print(k + 1)
