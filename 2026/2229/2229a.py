t  = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    m1, m2 = min(a), max(a)
    print((m2 - m1 + 1) // 2)
