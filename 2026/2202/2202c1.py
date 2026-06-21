t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    stack = []
    for x in a:
        while stack and stack[-1] != x - 1:
            stack.pop()
        if not stack:
            ans += 1
        stack.append(x)
    print(ans)
