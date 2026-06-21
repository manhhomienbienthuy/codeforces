t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n - 1):
        if a[i] > a[i + 1]:
            print('YES')
            print(2)
            print(a[i], a[i + 1])
            break
    else:
        print('NO')
