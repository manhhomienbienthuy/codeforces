t = int(input())

for _ in range(t):
    n = int(input())
    m = sum(i & 1 for i in map(int, input().split()))
    if m & 1 or 0 < m < n:
        print('YES')
    else:
        print('NO')
