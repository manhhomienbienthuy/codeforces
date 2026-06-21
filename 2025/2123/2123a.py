t = int(input())
for _ in range(t):
    n = int(input())
    r = (n - 1) % 4
    print('Alice' if r < 3 else 'Bob')
