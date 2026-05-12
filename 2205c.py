t = int(input())
for _ in range(t):
    n = int(input())
    b = []
    for i in range(n):
        x = list(map(int, input().split()))
        s = set()
        b.append([i for i in x[:0:-1] if not (i in s or s.add(i))])
    ans = []
    while b:
        ans += min(b)
        r = []
        for i in range(len(b) - 1, -1, -1):
            b[i] = [j for j in b[i] if j not in ans]
            if not b[i]:
                r.append(i)
        for i in r:
            del b[i]
    print(*ans)
