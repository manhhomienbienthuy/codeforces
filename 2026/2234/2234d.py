t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = input()
    b = input()
    one_a = one_b = one_c = 0
    for i in range(n):
        one_a += a[i] == '1'
        one_b += b[i] == '1'
        one_c += a[i] != b[i]
    sa = one_a * (n - one_a)
    sb = one_b * (n - one_b)
    sc = one_c * (n - one_c)
    q, r = divmod((1 << k) + 1, 3)
    print(q * (sa + sb + sc) + r // 2 * (sa + sb))
