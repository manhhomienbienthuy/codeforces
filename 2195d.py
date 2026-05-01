t = int(input())
for _ in range(t):
    n = int(input())
    f = list(map(int, input().split()))
    d = [f[i - 1] - f[i] for i in range(1, n)]
    a = [(d[i] - d[i + 1]) // 2 for i in range(n - 2)]
    r = f[0] - sum(a[i] * (i + 1) for i in range(n - 2))
    a.append(r // (n - 1))
    l = f[1] - sum(a[i] * i for i in range(n - 1))
    print(l, *a)

# f1 = a1*0 + a2*1 + a3*2 + a4*3
# f2 = a1*1 + a2*0 + a3*1 + a4*2
# f3 = a1*2 + a2*1 + a3*0 + a4*1
# f4 = a1*3 + a2*2 + a3*1 + a4*0

# d1 = f1 - f2 = -a1 + a2 + a3 + a4
# d2 = f2 - f3 = -a1 -a2 + a3 + a4
# d3 = f3 - f4 = -a1 -a2 -a3 + a4
# d4 = f4 - f1 =
