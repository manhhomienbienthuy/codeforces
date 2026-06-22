t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    while s[0] == '0':
        s = s[1:] + s[0]
    ans = cnt = 0
    for i in range(n):
        if s[i] == '0':
            cnt += 1
        else:
            ans = max(ans, cnt)
            cnt = 0
    print(max(ans, cnt))
