t = int(input())
for _ in range(t):
    s = input()
    length = len(s)
    d = 0
    for i in range(length - 1):
        if s[i] == s[i + 1]:
            d += 1
    print('YES' if d <= 2 else 'NO')
