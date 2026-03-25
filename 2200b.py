t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    sa = sorted(a)
    if a == sa:
        print(n)
    else:
        print(1)
