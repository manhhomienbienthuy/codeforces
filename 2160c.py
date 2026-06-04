t = int(input())
for _ in range(t):
    n = int(input())
    while n > 0 and n & 1 == 0:
        n >>= 1
    if n == 0:
        print('yes')
        continue
    if n == 1:
        print('no')
        continue
    l, r = n.bit_length() - 1, 0
    while l > r:
        if (n >> l & 1) ^ (n >> r & 1):
            print('no')
            break
        l, r = l - 1, r + 1
    else:
        if l == r and n >> l & 1:
            print('no')
        else:
            print('yes')
