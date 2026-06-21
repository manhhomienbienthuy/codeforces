t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    chk = [False] * n
    for i in range(n):
        if not chk[i]:
            si = {i + 1}
            sv = {a[i]}
            chk[i] = True
            while 2 * i + 1< n:
                i = 2 * i + 1
                chk[i] = True
                si.add(i + 1)
                sv.add(a[i])
            if si != sv:
                print('NO')
                break
    else:
        print('YES')
