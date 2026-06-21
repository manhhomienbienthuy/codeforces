t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    odd, even = 0, 1
    i = 0
    while (odd <= a and even <= b) or (odd <= b and even <= a):
        i += 1
        if i & 0x1:
            odd += 2 ** i
        else:
            even += 2 ** i
    print(i)
