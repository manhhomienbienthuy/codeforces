t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    if a[n - 1] != b[n - 1]:
        print('NO')
        continue
    for i in range(n - 1):
        x = a[i] ^ b[i]
        if x and x != a[i + 1] and x != b[i + 1]:
            print('NO')
            break
    else:
        print('YES')
