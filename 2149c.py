t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = map(int, input().split())
    k_count = 0
    under_k = [True] * k
    suk = k
    for x in a:
        if x > k:
            continue
        if x == k:
            k_count += 1
            continue
        suk -= under_k[x]
        under_k[x] = False
    print(max(k_count, suk))
