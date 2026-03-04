t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    sorted_a = sorted(set(a))
    count = 0
    for i in range(n):
        for x in sorted_a:
            j = a[i] * x + i
            if j >= n:
                break
            count += a[j] == x
    print(count)
