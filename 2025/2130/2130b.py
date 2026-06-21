t = int(input())
for _ in range(t):
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    sa = sum(a)
    if s < sa:
        print(*a)
    elif s == sa:
        print(-1)
    elif s == sa + 1:
        q = [0] * a.count(0) + [2] * a.count(2) + [1] * a.count(1)
        print(*q)
    else:
        print(-1)
