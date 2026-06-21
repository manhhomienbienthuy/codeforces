t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    s += s[0]
    ans = 1
    for i in range(n):
        ans += s[i] != s[i + 1]
    print(min(n, ans))
