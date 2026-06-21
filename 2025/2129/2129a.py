t = int(input())
for _ in range(t):
    n = int(input())
    a = [list(map(int, input().split())) + [i + 1] for i in range(n)]
    a = sorted(a, key=lambda x: (x[0], -x[1]))
    result = []
    curr = 0
    for pair in a:
        if curr < pair[1]:
            curr = pair[1]
            result.append(pair[2])
    print(len(result))
    print(*result, sep="\n")
