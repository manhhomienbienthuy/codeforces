t = int(input())
for _ in range(t):
    x = int(input())
    count = 0
    for d in range(82):
        if sum(map(int, str(x + d))) == d:
            count += 1
    print(count)
