t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if any(a[i] > i for i in range(n)):
        print('no')
        continue
    print('yes')
    ans = []
    def move(n, fr, to, tmp):
        if n == 0:
            return
        move(n - a[n - 1] - 1, fr, tmp, to)
        r = a[n - 1] + 1
        for i in range(n - 1, n - r - 1, -1):
            if a[i] + 1 == r:
                ans.append((i + 1, fr, to))
                r -= 1
            else:
                break
        if r > 0:
            move(n - a[n - 1] - 1, tmp, fr, to)
            move(n - (a[n - 1] + 1 - r), fr, to, tmp)
        else:
            move(n - a[n - 1] - 1, tmp, to, fr)
    move(n, 1, 3, 2)
    print(len(ans))
    for x in ans:
        print(*x)
