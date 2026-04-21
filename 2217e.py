t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    d = list(map(int, input().split()))

    q = [0] * n
    count = [0] * n

    try:
        for v in range(n, 0, -1):
            idx = next(i for i in range(n) if not q[i] and count[i] == d[i])
            q[idx] = v
            for i in range(idx):
                if not q[i] and p[i] < p[idx]:
                    count[i] += 1
        print(*q)
    except StopIteration:
        print(-1)
