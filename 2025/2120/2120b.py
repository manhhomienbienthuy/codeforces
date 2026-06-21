t = int(input())
for _ in range(t):
    n, s = map(int, input().split())
    result = 0
    for i in range(n):
        a, b, x, y = map(int, input().split())
        if a + b == 0:
            result += x + y == s
        else:
            result += x == y
    print(result)
