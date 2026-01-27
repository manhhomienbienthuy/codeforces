t = int(input())
for _ in range(t):
    n, s, x = map(int, input().split())
    a = sum(map(int, input().split()))
    print(('YES', 'NO')[a > s or (a - s) % x > 0])
