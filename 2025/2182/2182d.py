MOD = 998244353

fact = [1] * 55
for i in range(1, 55):
    fact[i] = fact[i - 1] * i

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    k, r = divmod(s, n)
    bad = 0
    miss = 0
    is_over = False
    for x in a[1:]:
        if x < k:
            miss += k - x
            bad += 1
        elif x == k:
            bad += 1
        elif x > (k + (r > 0)):
            is_over = True
            break
    if is_over or a[0] < miss:
        print(0)
        continue
    a[0] -= miss
    ans = fact[n - bad + a[0]] * fact[bad - a[0]] * fact[bad] // fact[a[0]] // fact[bad - a[0]]
    print(ans % MOD)
