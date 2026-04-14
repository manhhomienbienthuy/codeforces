from math import sqrt

t = int(input())
for _ in range(t):
    p, q = map(int, input().split())
    t = p + 2 * q
    for n in range(1, int(sqrt(p / 2 + q) + 1)):
        if not (t - n) % (2 * n + 1):
            m = (t - n) // (2 * n + 1)
            if p >= m - n:
                print(n, m)
                break
    else:
        print(-1)
