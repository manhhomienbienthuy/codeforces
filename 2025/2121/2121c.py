t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    res = 0
    a = []
    for i in range(n):
        line = list(map(int, input().split()))
        a.append(line)
        res = max(res, *line)
    b = []
    for j in range(m):
        b.append([a[i][j] for i in range(n)])
    row = [line.count(res) for line in a]
    col = [line.count(res) for line in b]
    s = sum(row)
    flag = False
    for i in range(n):
        for j in range(m):
            adj = a[i][j] == res
            if row[i] + col[j] - adj == s:
                print(res - 1)
                flag = True
                break
        if flag:
            break
    else:
        print(res)
