t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if any(x for x in a if x % 2 == 1) and any(x for x in a if x % 2 == 0):
        print(*sorted(a))
    else:
        print(*a)
