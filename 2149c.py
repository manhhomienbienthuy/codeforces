t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = sorted(map(int, input().split()))
    k_count = a.count(k)
    under_k = [1] * k
    for i in a:
        if i >= k:
            break
        under_k[i] = 0
    print(max(k_count, sum(under_k)))
