MODULO = 998244353

t = int(input())
for _ in range(t):
    n = int(input())
    p = [int(x) for x in input().split()]
    q = [int(x) for x in input().split()]
    mp, mq = 0, 0
    for i in range(n):
        if p[i] > p[mp]:
            mp = i
        if q[i] > q[mq]:
            mq = i
        if p[mp] > q[mq]:
            print((pow(2, p[mp], MODULO) + pow(2, q[i - mp], MODULO)) % MODULO, end=" ")
        elif p[mp] < q[mq]:
            print((pow(2, q[mq], MODULO) + pow(2, p[i - mq], MODULO)) % MODULO, end=" ")
        else:
            print((pow(2, q[mq], MODULO) + pow(2, max(q[i - mp], p[i - mq]), MODULO)) % MODULO, end=" ")
    print()
