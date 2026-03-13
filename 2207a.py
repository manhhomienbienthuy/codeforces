t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    while '101' in s:
        s = s.replace('101', '111')
    maxx = s.count('1')
    for i in range(1, n - 1):
        if s[i - 1: i + 2] == '111':
            s = s[:i] + '0' + s[i + 1:]
    minn = s.count('1')
    print(minn, maxx)
