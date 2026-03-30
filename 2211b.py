modulo = 676767677

t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    n = abs(x - y)
    if n < 2:
        print(1)
    else:
        result = 2 + sum(n % i == 0 for i in range(2, n // 2 + 1))
        print(result % modulo)
    print('1 ' * x + '-1 ' * y)
