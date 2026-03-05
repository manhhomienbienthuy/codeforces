t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    a = list(map(int, input().split()))
    while p and a:
        if a[-1] != p[-1]:
            p.pop()
        else:
            a.pop()
    print('YES' if p else 'NO')
