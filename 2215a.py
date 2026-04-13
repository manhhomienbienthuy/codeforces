t = int(input())
for _ in range(t):
    n, k, p, q = map(int, input().split())
    a = list(map(int, input().split()))
    calc_p = [x % p % q for x in a]
    calc_q = [x % q % p for x in a]
    calc_min = [min(x, y) for (x, y) in zip(calc_p, calc_q)]
    ssmin = sum(calc_min)
    smin, sp, sq = sum(calc_min[:k]), sum(calc_p[:k]), sum(calc_q[:k])
    window_diff = min(sp - smin, sq - smin)
    for i in range(1, n - k + 1):
        smin = smin - calc_min[i - 1] + calc_min[i + k - 1]
        sq = sq - calc_q[i - 1] + calc_q[i + k - 1]
        sp = sp - calc_p[i - 1] + calc_p[i + k - 1]
        window_diff = min(window_diff, sp - smin, sq - smin)
    print(ssmin + window_diff)
