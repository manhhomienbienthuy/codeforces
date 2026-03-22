t = int(input())
for _ in range(t):
    n, h = map(int, input().split())
    a = list(map(int, input().split()))
    calc = [0] * n
    for i in range(n):
        m = i
        for k in range(i, -1, -1):
            if a[k] > a[m]:
                m = k
            calc[i] += h - a[m]

        m = i
        for k in range(i + 1, n):
            if a[k] > a[m]:
                m = k
            calc[i] += h - a[m]

    result = 0
    for i in range(n):
        m = i
        for j in range(i, n):
            if a[j] > a[m]:
                m = j

            total = calc[i] + calc[j] - calc[m]

            if total > result:
                result = total

    print(result)
