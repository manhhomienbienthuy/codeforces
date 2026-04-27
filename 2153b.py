t = int(input())
for _ in range(t):
    x, y, z = map(int, input().split())
    b, c, a = x | y, y | z, z | x
    if a & b == x and b & c == y and c & a == z:
        print('YES')
    else:
        print('NO')
