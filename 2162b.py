t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    ans = []
    for i in range(n):
        if s[i] == '1':
            ans.append(i + 1)
    print(len(ans))
    print(*ans)
