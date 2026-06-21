t = int(input())
for _ in range(t):
    input()
    a = list(map(int, input().split()))
    print('YES' if 100 in a else 'NO')
