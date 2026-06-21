t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    l = p.index(n) + 1
    ans = []
    low = p[0]
    for i in range(l - 1):
        ans.append((p[i], n))
        low = min(low, p[i])
    while l < n:
        for i in range(n - 1, l - 1, -1):
            if p[i] > low:
                for j in range(l, i + 1):
                    if p[j] > low:
                        ans.append((low, p[j]))
                    else:
                        ans.append((p[j], p[i]))
                l = i + 1
                low = min(p[:l])
                break
        else:
            print('NO')
            break
    else:
        print('YES')
        for x in ans:
            print(*x)
