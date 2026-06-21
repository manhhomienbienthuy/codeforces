t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    if y < 0 and x < 4 * (0 - y):
        print('NO')
        continue
    if x < 2 * y or x + y < 3 or (x + y) % 3:
        print('NO')
        continue
    print('YES')
