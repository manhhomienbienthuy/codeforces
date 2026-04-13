t = int(input())
for _ in range(t):
    n, k, p, q = map(int, input().split())
    a = list(map(int, input().split()))
    calc_p = [-1] * n
    calc_q = [-1] * n
    calc_min = [-1] * n
    ssmin, smin, sp, sq = 0, 0, 0, 0
    for i in range(n):
        calc_p[i] = a[i] % p % q
        calc_q[i] = a[i] % q % p
        calc_min[i] = min(calc_p[i], calc_q[i])
        ssmin += calc_min[i]
        if i < k:
            smin += calc_min[i]
            sp += calc_p[i]
            sq += calc_q[i]
    window_diff = sp - smin
    if sq - smin < window_diff:
        window_diff = sq - smin
    for i in range(1, n - k + 1):
        smin = smin - calc_min[i - 1] + calc_min[i + k - 1]
        sq = sq - calc_q[i - 1] + calc_q[i + k - 1]
        sp = sp - calc_p[i - 1] + calc_p[i + k - 1]
        if sp - smin < window_diff:
            window_diff = sp - smin
        if sq - smin < window_diff:
            window_diff = sq - smin
    print(ssmin + window_diff)
