t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    if n < 3:
        print(1)
        continue
    l = -1
    r = l + 1
    ans = 0
    while l < n:
        while r < n and s[r] == '0':
            r += 1
        ans += r < n
        if l == -1 and r == n:
            ans = 1 + (n - 2) // 3 + ((n - 2) % 3 == 2)
            break
        d = r - l - 1
        ans += d // 3
        if r == n or l == -1:
            ans += (d % 3 == 2)
        l, r = r, r + 1
    print(ans)
