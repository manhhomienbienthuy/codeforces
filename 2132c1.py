t = int(input())
for _ in range(t):
    n = int(input())
    s = []
    while n > 0:
        s.append(n % 3)
        n //= 3
    ans = s[0] * 3
    for i in range(1, len(s)):
        ans += s[i] * 3 ** (i + 1) + s[i] * i * 3 ** (i - 1)
    print(ans)
