t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    if a[n - 1] == b[n - 1]:
        print(n)
        continue

    suf = set()
    for i in range(n - 2, -1, -1):
        if a[i] == b[i]:
            print(i + 1)
            break
        if a[i] == a[i + 1] or b[i] == b[i + 1]:
            print(i + 1)
            break
        if a[i] in suf or b[i] in suf:
            print(i + 1)
            break
        suf.add(a[i + 1])
        suf.add(b[i + 1])
    else:
        print(0)
