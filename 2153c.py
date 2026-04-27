t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()), reverse=True)

    pairs_sum = 0
    pairs_len = 0
    singles = []

    i = 0
    while i < n:
        if i + 1 < n and a[i] == a[i + 1]:
            pairs_sum += 2 * a[i]
            pairs_len += 2
            i += 2
        else:
            singles.append(a[i])
            i += 1

    if pairs_sum == 0:
        print(0)
        continue

    if not singles:
        print(pairs_sum)
        continue

    prev = singles[0]
    for cur in singles[1:]:
        if prev < cur + pairs_sum:
            print(pairs_sum + prev + cur)
            break
        prev = cur
    else:
        if prev < pairs_sum:
            print(pairs_sum + prev)
        else:
            print(pairs_sum if pairs_len > 2 else 0)
