t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    if n == 2:
        print('Alice' if s[0] == 'A' else 'Bob')
        continue
    if s.count('B') >= 2 and (s[n - 1] == 'B' or s[0] == s[n - 2] == 'B'):
        print('Bob')
        continue
    print('Alice')
