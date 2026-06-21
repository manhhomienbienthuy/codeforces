t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = []
    while n > 0:
        s.append(n % 3)
        n //= 3
    ss = sum(s)
    if ss > k:
        print(-1)
        continue
    x = (k - ss) // 2
    while x and len(s) > 1:
        y = min(s[-1], x)
        s[-1] -= y
        s[-2] += 3 * y
        x -= y
        if s[-1] == 0:
            s.pop()
    ans = 0
    for i in range(len(s)):
        ans += s[i] * 3 ** (i + 1)
        if i > 0:
             ans += s[i] * i * 3 ** (i - 1)
    print(ans)
