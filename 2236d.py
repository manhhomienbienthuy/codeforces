t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = sorted(map(int, input().split()))

    ok = False
    i = 0

    while i < n:
        j = i
        while j + 1 < n and a[j + 1] - a[j] <= k:
            j += 1

        length = j - i + 1
        if a[i] == a[j]:
            if length % 2 == 0:
                ok = True
                break
        else:
            if length >= 2:
                ok = True
                break

        if ok:
            break

        i = j + 1

    print("YES" if ok else "NO")
