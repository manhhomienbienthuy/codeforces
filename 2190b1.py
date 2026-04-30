t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    d = [0] * n
    d[0] = int(s[0] == '(')
    for i in range(n):
        d[i] = d[i - 1] + (s[i] == '(')
    found = False
    for i in range(n):
        if s[i] == ')' and d[n - 1] - d[i] > 1:
            print(n - 2)
            found = True
            break
    else:
        print(-1)
        continue
