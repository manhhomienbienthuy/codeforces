from math import lcm, gcd

PRIMES = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    g = [1] + [gcd(a[i], a[i + 1]) for i in range(n - 1)] + [1]

    cand = []

    for i in range(n):
        vals = []
        vals.append(a[i])

        base = lcm(g[i], g[i + 1])
        for p in PRIMES:
            m = base * p
            if m > b[i]:
                break
            if m != a[i]:
                vals.append(m)

        cand.append(vals)

    dp_prev = [int(cand[0][i] != a[0]) for i in range(len(cand[0]))]
    for i in range(1, n):
        dp_cur = [-1] * len(cand[i])
        for j, prev in enumerate(cand[i - 1]):
            if dp_prev[j] == -1:
                continue
            for k, cur in enumerate(cand[i]):
                if gcd(prev, cur) == g[i]:
                    dp_cur[k] = max(dp_cur[k], dp_prev[j] + (cur != a[i]))
        dp_prev = dp_cur

    print(max(dp_prev))
