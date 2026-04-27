t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    x = map(int, input().split())
    ans = sum(a)
    count = [0] * 2
    for i in x:
        count[i & 1] += 1
    for i in range(2):
        sa = sorted(a[1 - i::2], reverse=True)
        j = 0
        while j < count[i] and j < (n + i) // 2 and sa[j] > 0:
            j += 1
        if count[i] and j == 0:
            j = 1
        ans -= sum(sa[:j])
    print(ans)
