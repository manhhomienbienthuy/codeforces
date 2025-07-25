t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = input().split()
    first = a.index('1')
    last = n - a[::-1].index('1')
    diff = last - first
    print('YES' if diff <= x else 'NO')
