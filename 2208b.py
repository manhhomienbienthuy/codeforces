t = int(input())
for _ in range(t):
    n, k, p, m = map(int, input().split())
    a = list(map(int, input().split()))
    a = [(a[i], i == p - 1) for i in range(n)]
    results = 0
    while m > 0:
        choose = 0
        if a[choose][1]:
            m -= a[choose][0]
            if m >= 0:
                results += 1
            a = a[:choose] + a[choose + 1:] + [a[choose]]
            continue
        for i in range(1, k):
            if a[i][1]:
                choose = i
                m -= a[choose][0]
                if m >= 0:
                    results += 1
                a = a[:choose] + a[choose + 1:] + [a[choose]]
                break
            else:
                if a[i][0] < a[choose][0]:
                    choose = i
        else:
            m -= a[choose][0]
            a = a[:choose] + a[choose + 1:] + [a[choose]]
    print(results)
