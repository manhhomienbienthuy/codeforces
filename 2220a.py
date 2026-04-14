t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()), reverse=True)
    if len(set(a)) < n:
        print(-1)
    else:
        print(*a)
