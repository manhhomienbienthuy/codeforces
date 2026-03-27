t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a = [0] * n
    i = 0
    while a[i] == 0:
        a[i] = 1
        if s[i] == 'R':
            i += 1
        else:
            i -= 1
    print(sum(a))
