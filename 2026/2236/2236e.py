def good(a, l):
    if len(a) < l:
        return False
    a = sorted(a)
    for i in range(l - 1):
        if a[i + 1] - a[i] > 1:
            return False
    return True

def check(a, l):
    if l == 0:
        return True

    for i in range(n - l + 1):
        a1 = a[i : i + l]
        if not good(a1, l):
            continue

        for j in range(n - l + 1):
            if j + l > i and j < i + l:
                continue
            a2 = a[j : j + l]
            if not good(a2, l):
                continue

            if good(a1 + a2, 2 * l):
                return True

    return False

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    left, right = 0, n // 2

    while left <= right:
        mid = (left + right) // 2
        if check(a, mid):
            left = mid + 1
        else:
            right = mid - 1
    print(right)
