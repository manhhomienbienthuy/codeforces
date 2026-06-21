t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted(a)
    if a == b:
        print(-1)
    else:
        print(min(max(a[i] - b[0], b[-1] - a[i]) 
                  for i in range(n) if a[i] != b[i]))
