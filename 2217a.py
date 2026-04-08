t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = sum(map(int, input().split()))
    if s & 1 or 1 - (n * k) & 1:
        print("YES")
    else:
        print("NO")
