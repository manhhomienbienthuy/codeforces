C = [[0] * 33 for _ in range(33)]
for i in range(1, 33):
    C[i][1] = 1
    for j in range(2, i + 1):
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j]

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    d = n.bit_length() - 1
    ans = int(d + 1 > k)
    for i in range(1, d + 1):
        for j in range(1, i + 1):
            if i + j - 1 > k:
                ans += C[i][j]
    print(ans)
