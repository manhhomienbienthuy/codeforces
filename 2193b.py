t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    for i in range(n - 1):
        if p[i] != n - i:
            break
    else:
        i = n
    for j in range(i + 1, n):
        if p[j] == n - i:
            break
    else:
        j = n
    p = p[:i] + p[i:j+1][::-1] + p[j + 1:]
    print(*p)
