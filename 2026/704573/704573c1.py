n, k = map(int, input().split())
a = list(map(int, input().split()))

l, r = 1, sum(a) // k
while l <= r:
    m = (l + r) // 2
    s = sum(x // m for x in a)
    if s >= k:
        l = m + 1
    else:
        r = m - 1

print(r)
