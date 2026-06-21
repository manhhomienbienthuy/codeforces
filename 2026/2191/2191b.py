t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    count = [0] * (n + 1)
    for x in a:
        count[x] += 1
    if count[0] == 0:
        print('NO')
        continue
    if count[0] == 1:
        print('YES')
        continue
    print('YES' if count[1] else 'NO')
