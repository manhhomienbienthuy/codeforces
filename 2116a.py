t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    x1, x2 = min(a, c), min(b, d)
    print('Flower' if x1 < x2 else 'Gellyfish')
