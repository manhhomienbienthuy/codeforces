t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    s = a + b + c
    if s % 3:
        print('NO')
    else:
        avg = s // 3
        print('YES' if avg >= b else 'NO')
