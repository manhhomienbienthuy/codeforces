t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    curr = 10 ** 9
    for x in a:
        if x > 2 * curr - 1:
            print('NO')
            break
        curr = min(curr, x)
    else:
        print('YES')
