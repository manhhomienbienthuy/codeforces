t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    c = a ^ b
    if c == 0:
        print(0)
        continue
    if c < a:
        print(1)
        print(c)
        continue
    d = c.bit_length()
    if d <= a.bit_length():
        print(2)
        print(c ^ (1 << (d - 1)), 1 << (d - 1))
    else:
        print(-1)
