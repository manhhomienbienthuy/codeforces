t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    count, right = 0, 0
    for i in range(n):
        if a[i] != b[i]:
            count += 1
            right = i
    if not count & 0x1:
        print('Tie')
    else:
        print(('Ajisai', 'Mai')[right & 0x1])
