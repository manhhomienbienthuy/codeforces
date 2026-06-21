t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    l = p.index(n) + 1
    low = min(p[:l])
    while l < n:
        for i in range(n - 1, l - 1, -1):
            if p[i] > low:
                l = i + 1
                low = min(p[:l])
                break
        else:
            print('NO')
            break
    else:
        print('YES')
