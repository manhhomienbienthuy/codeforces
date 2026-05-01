t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    div6 = []
    div2 = []
    div3 = []
    other = []
    for x in a:
        if x % 6 == 0:
            div6.append(x)
        elif x % 2 == 0:
            div2.append(x)
        elif x % 3 == 0:
            div3.append(x)
        else:
            other.append(x)
    print(*div6, *div2, *other, *div3)
