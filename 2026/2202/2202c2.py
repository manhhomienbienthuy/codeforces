t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    stack = []
    ans = 0
    for i in range(n):
        while stack and a[stack[-1]] != a[i] - 1:
            stack.pop()
        if stack:
            prev = stack[-1]
        else:
            prev = -1
        ans += (i - prev) * (n - i)
        stack.append(i)
    print(ans)
