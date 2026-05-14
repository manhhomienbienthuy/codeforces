def count_digits(n):
    cnt, pos = [0] * 10, 1
    while pos <= n:
        high, cur, low = n // (pos * 10), (n // pos) % 10, n % pos
        for d in range(1, 10):
            cnt[d] += high * pos + (pos if d < cur else (low + 1 if d == cur else 0))
        pos *= 10
    return cnt

t = int(input())
for _ in range(t):
    k = int(input())
    cnt, d, b = 0, 1, 9
    while cnt + d * b <= k:
        cnt += d * b
        d += 1
        b *= 10

    if d == 1:
        print(k * (k + 1) // 2)
        continue

    q, r = divmod(k - cnt, d)
    n = 10 ** (d - 1) + q
    x = count_digits(n - 1)
    print(sum(i * x[i] for i in range(1,10)) + sum(map(int, str(n)[:r])))
