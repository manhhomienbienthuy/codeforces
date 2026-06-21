t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    print('0' * (n - k) + '1' * k)
