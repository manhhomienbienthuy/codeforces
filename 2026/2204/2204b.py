t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    cur_max = 0
    result = 0
    for i in a:
        if i >= cur_max:
            cur_max = i
            result += 1
    print(result)
