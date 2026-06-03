t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    if k & 1:
        print(*[n] * k)
        continue

    a = [0] * k
    l = -1
    d = n.bit_length() - 1
    for i in range(d, -1, -1):
        if (n >> i) & 1:
            l += l < k - 1
            for j in range(k):
                if j == l:
                    continue
                a[j] |= 1 << i
        else:
            for j in range(l + (l & 1)):
                a[j] |= 1 << i
    print(*a)
