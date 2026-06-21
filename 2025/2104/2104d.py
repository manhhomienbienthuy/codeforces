N = 10**7
sieve = [True] * (N + 1)
sieve[0] = sieve[1] = False
for i in range(4, N + 1, 2):
    sieve[i] = False

primes = [2]
for i in range(3, N + 1, 2):
    if sieve[i]:
        primes.append(i)
        if len(primes) >= 400000:
            break
        for j in range(i * i, N + 1, i):
            sieve[j] = False

t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    b = primes[:n]
    s = sum(a) - sum(b)
    ans = 0
    while s < 0:
        s = s - a[ans] + b[n - ans - 1]
        ans += 1
    print(ans)
