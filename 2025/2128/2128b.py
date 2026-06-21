t = int(input())
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    l, r = 0, n - 1
    for i in range(n - 1):
        if (p[l] < p[r]) ^ (i % 2):
            print("L", end="")
            l += 1
        else:
            print("R", end="")
            r -= 1
    print("R")
