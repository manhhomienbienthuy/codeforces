MOD = 676767677

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    b = list(map(int, input().split()))

    cnt = [0] * m
    for v in b:
        cnt[v] += 1
    S = [0] * (m + 1)
    for v in range(1, m + 1):
        S[v] = S[v - 1] + cnt[v - 1]

    result = 1
    ok = True

    for i in range(n):
        if b[i] == 0:
            continue

        ni = m
        if i > 0:
            ni = min(ni, b[i - 1])
        if i < n - 1:
            ni = min(ni, b[i + 1])

        if ni >= b[i]:
            ok = False
            break

        if ni == b[i] - 1:
            c = S[b[i]]
        else:
            c = S[b[i]] - S[b[i] - 1]

        result = result * c % MOD

    print(result if ok else 0)
