t = int(input())

for _ in range(t):
    n = int(input())
    m = sum(i & 1 for i in map(int, input().split()))
    if m == 0:
        print("NO")
    elif m == n:
        print("YES" if m & 1 else "NO")
    else:
        print("YES")
