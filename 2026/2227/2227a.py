t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    print(('YES', 'NO')[x & 1 and y & 1])
