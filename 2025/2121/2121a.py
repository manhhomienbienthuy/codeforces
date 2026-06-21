t = int(input())
for _ in range(t):
    n, s = map(int, input().split())
    x = list(map(int, input().split()))
    if n > 1:
        print(x[-1] - x[0] + min(abs(s - x[0]), abs(s - x[-1])))
    else:
        print(abs(s - x[0]))
