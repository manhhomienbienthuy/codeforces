t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()), reverse=True)
    other = []
    result = result_len = l = 0
    i = 0
    while i < n:
        if i == n - 1:
            other.append(a[i])
            l += 1
            break
        elif a[i] == a[i + 1]:
            result += 2 * a[i]
            result_len += 2
            i += 2
        else:
            other.append(a[i])
            l += 1
            i += 1
    if not result:
        print(0)
        continue
    if l == 0:
        print(result)
        continue
    prev = other[0]
    for i in range(1, l):
        cur = other[i]
        if prev < cur + result:
            print(result + prev + cur)
            break
        prev = cur
    else:
        if prev < result:
            print(result + prev)
        else:
            print(result if result_len > 2 else 0)
