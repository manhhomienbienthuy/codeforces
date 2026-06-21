t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    input()
    b = list(enumerate(map(int, input().split())))
    b = sorted(b, key=lambda x: x[1], reverse=True)
    print(n * (k + 1) - sum(x[1] for x in b))
    for i, x in b:
        for j in range(x, k + 1):
            print(i + 1, end=" ")
    print()
