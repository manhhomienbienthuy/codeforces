t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    used = [False] * (n + 1)
    for x in a:
        used[x] = True
    choice = []
    for i in range(1, n + 1):
        if not used[i]:
            choice.append(i)
            if len(choice) >= min(3, k):
                break
    last = a[n - 1]
    l = len(choice)
    if l == 0:
        choice = a[:3]
        l = 3
    elif l == 2 < k:
        choice.append(last)
        l += 1
    elif l == 1 < k:
        for i in range(1, n + 1):
            if i != last and i != choice[0]:
                choice.append(i)
                choice.append(last)
                l += 2
                break
    ans = choice * (k // l)
    print(*ans, *choice[:k % l])
