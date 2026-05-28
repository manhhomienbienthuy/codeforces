N = 5 * 10**4
sieve = [True] * (N + 1)
sieve[0] = sieve[1] = False
for i in range(4, N + 1, 2):
    sieve[i] = False
for i in range(3, N + 1, 2):
    if sieve[i]:
        for j in range(i * i, N + 1, i):
            sieve[j] = False

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(range(n + 1))
    for i in range(n // 2, 1, -1):
        if sieve[i]:
            prev = i
            nxt = i * 2
            while True:
                while nxt <= n and a[nxt] != nxt:
                    nxt += i
                if nxt > n:
                    break
                a[prev], a[nxt] = a[nxt], a[prev]
                prev, nxt = nxt, nxt + i
    print(*a[1:])
