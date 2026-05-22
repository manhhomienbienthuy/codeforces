t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ans = []
    for i in range(n):
        if a[i] % 2 and b[i] % 2 == 0:
            continue

        if a[i] % 2 == 0 and b[i] % 2:
            ans.append((3, i + 1))
            a[i], b[i] = b[i], a[i]
            continue

        if a[i] % 2 == 0:
            for j in range(i + 1, n):
                if a[j] % 2:
                    for k in range(j - 1, i - 1, -1):
                        ans.append((1, k + 1))
                        a[k], a[k + 1] = a[k + 1], a[k]
                    break

        if b[i] % 2 == 1:
            for j in range(i + 1, n):
                if b[j] % 2 == 0:
                    for k in range(j - 1, i - 1, -1):
                        ans.append((2, k + 1))
                        b[k], b[k + 1] = b[k + 1], b[k]
                    break

    for i in range(n - 1, -1, -1):
        for j in range(i):
            if a[j] > a[j + 1]:
                ans.append((1, j + 1))
                a[j], a[j + 1] = a[j + 1], a[j]
            if b[j] > b[j + 1]:
                ans.append((2, j + 1))
                b[j], b[j + 1] = b[j + 1], b[j]

    print(len(ans))
    for x in ans:
        print(*x)
