t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    p0, p1 = s.count('0'), s.count('1')
    while k > 0:
        if p0 > p1:
            p0 -= 2
        else:
            p1 -= 2
        k -= 1

    print('YES' if p0 == p1 else 'NO')
