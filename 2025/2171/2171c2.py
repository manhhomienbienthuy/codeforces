t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    x = 0
    for i in range(n):
        x ^= (a[i] ^ b[i])
    if x == 0:
        print("Tie")
        continue

    bit = x.bit_length() - 1
    for i in range(n - 1, -1, -1):
        if ((a[i] ^ b[i]) >> bit) & 1:
            print("Ajisai" if i % 2 == 0 else "Mai")
            break
