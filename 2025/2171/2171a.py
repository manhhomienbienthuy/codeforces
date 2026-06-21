t = int(input())
for _ in range(t):
    n = int(input())
    print((~n & 0x1) * (1 + (n >> 2)))
