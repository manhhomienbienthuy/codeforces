t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    if n - min(len(set(s[1:])), len(set(s[:-1]))) > 1:
        print('YES')
    else:
        print('NO')
