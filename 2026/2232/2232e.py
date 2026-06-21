MOD = 10**9 + 7

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())

    anti = []
    for i in range(n):
        anti.append([-1] * (i + 1))

    for i in range(k):
        s = int(input())
        data = input().split()
        r, c = int(data[0]) - 1, int(data[1]) - 1
        path = data[2] if len(data) > 2 else ""
        d = r + c
        anti[d][r] = (s + 1) // 2

        for ch in path:
            if ch == 'R':
                c += 1
            else:
                r += 1
            d = r + c
            if d >= n:
                break
            anti[d][r] = (s + 1) // 2

    ans = 1
    for i in range(n - 1):
        A = anti[i]
        B = anti[i + 1]
        if n - i - 1 in B:
            ways = 1
        else:
            low = 0
            high = i + 1
            for j in range(i + 1):
                if A[j] != -1:
                    if B[j] == A[j]:
                        low = j + 1
                    if B[j + 1] == A[j]:
                        high = min(high, j)
            ways = high - low + 1
        ans = ans * ways % MOD

    print(ans)
