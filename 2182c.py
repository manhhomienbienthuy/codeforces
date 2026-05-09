t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    l1 = 0
    for i in range(n):
        if all(a[j] < b[(j + i) % n] for j in range(n)):
            l1 += 1
    l2 = 0
    for i in range(n):
        if all(b[j] < c[(j + i) % n] for j in range(n)):
            l2 += 1
    print(n * l1 * l2)
