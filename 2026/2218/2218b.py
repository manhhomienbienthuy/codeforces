t = int(input())
for _ in range(t):
    a = sorted(map(int, input().split()))
    print(a[-1] - sum(a[:6]))
