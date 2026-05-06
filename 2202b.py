t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    if n & 1 and s[0] == 'b':
        print('NO')
        continue
    for i in range(n & 1, n - 1, 2):
        if s[i] == s[i + 1] != '?':
            print('NO')
            break
    else:
        print('YES')
