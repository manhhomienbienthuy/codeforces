t = int(input())
for _ in range(t):
    n = int(input())
    s = list(map(int, input()))
    a = sorted(s)
    if s == a:
        print('Bob')
    else:
        print('Alice')
        ans = [i + 1 for i in range(n) if s[i] != a[i]]
        print(len(ans))
        print(*ans)
