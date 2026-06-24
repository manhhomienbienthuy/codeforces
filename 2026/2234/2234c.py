t = int(input())
for _ in range(t):
    n = int(input())
    h = list(map(int, input().split()))

    for l in range(n):
        w = [0] * n
        for i in range(l + 1, l + n):
            w[i % n] = max(w[(i - 1) % n], h[(i - 1) % n])
        for i in range(l + n - 1, l, -1):
            if max(w[i % n], w[(i + 1) % n]) > h[i % n] and w[i % n] != w[(i + 1) % n]:
                w[i % n] = max(w[(i + 1) % n], h[i % n])
            else:
                break
        print(w)
        print(sum(w), end=' ')
    print()
