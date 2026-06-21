t = int(input())
for _ in range(t):
    a, b, x = map(int, input().split())
    A = [a]
    B = [b]
    while a > 0:
        a //= x
        A.append(a)
    while b > 0:
        b //= x
        B.append(b)
    ans = 10 ** 18
    for i in range(len(A)):
        for j in range(len(B)):
            ans = min(ans, abs(A[i] - B[j]) + i + j)
    print(ans)
