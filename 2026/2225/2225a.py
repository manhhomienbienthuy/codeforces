t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    print('YES' if y > 2 * x else 'NO')
