t = int(input())
for _ in range(t):
    n = int(input())
    a = [i + 1 for i in range(2 * n + 1)]
    result = []

    for found in range(3):
        l, r = 0, 2 * n + 1 - found
        while l < r - 1:
            mid = (l + r) // 2
            print('?', mid + found, *result, *a[:mid])
            x = int(input())
            if (mid + found - x) % 2:
                r = mid
            else:
                l = mid
        result.append(a[r - 1])
        a = a[:r - 1] + a[r:]
    print('!', *result)
