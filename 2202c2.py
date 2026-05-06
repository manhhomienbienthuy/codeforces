t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    seq = []
    stack = []
    for i in range(n):
        cur = []
        while stack and a[stack[-1]] != a[i] - 1:
            cur.append(stack.pop())
        if cur:
            seq.append(stack + cur[::-1])
        stack.append(i)
    seq.append(stack)
    ans = 0
    cur = [-1]
    for s in seq:
        if s[0] != cur[0]:
            l, r = s[0], n - 1 - s[-1]
            ans += (n * (n + 1) - l * (l + 1) - r * (r + 1)) // 2
            cur = s
        else:
            cur_n = n
            l, r = s[-1], n - 1 - s[-1]
            for j in range(len(s) - 1, 0, -1):
                if s[j] != s[j - 1] + 1:
                    l = s[j] - s[j - 1] - 1
                    cur_n = n - s[j - 1] - 1
                    break
            ans += (cur_n * (cur_n + 1) - l * (l + 1) - r * (r + 1)) // 2
    print(ans)
