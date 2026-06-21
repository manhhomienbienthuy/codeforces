t = int(input())
for _ in range(t):
    l1, b1, l2, b2, l3, b3 = map(int, input().split())
    if l1 == l2 == l3 == b1 + b2 + b3:
        print('yes')
    elif b1 == b2 == b3 == l1 + l2 + l3:
        print('yes')
    elif l1 == l2 + l3 == b1 + b2 == b1 + b3:
        print('yes')
    elif b1 == b2 + b3 == l1 + l2 == l1 + l3:
        print('yes')
    else:
        print('no')
