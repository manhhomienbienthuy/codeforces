t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    l = 1
    for i in range(1, n):
        if a[i] == a[i - 1]:
            l += 1
        else:
            if l >= m:
                print('NO')
                break
            l = 1
    else:
        print('YES' if l < m else 'NO')
