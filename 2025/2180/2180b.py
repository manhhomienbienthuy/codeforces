t = int(input())
for _ in range(t):
    n = int(input())
    a = input().split()
    s = ''
    for x in a:
        if x + s < s + x:
            s = x + s
        else:
            s = s + x
    print(s)
