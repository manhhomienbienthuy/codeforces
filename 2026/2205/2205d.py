t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    parent = [-1] * n
    left = [-1] * n
    right = [-1] * n

    stack = []
    root = -1
    for i in range(n):
        last = -1
        while stack and a[stack[-1]] < a[i]:
            last = stack.pop()

        if stack:
            right[stack[-1]] = i
            parent[i] = stack[-1]
        else:
            root = i

        if last != -1:
            left[i] = last
            parent[last] = i
        stack.append(i)

    q = [root]
    for u in q:
        if left[u] != -1:
            q.append(left[u])
        if right[u] != -1:
            q.append(right[u])

    sz = [0] * n
    dp = [0] * n

    for u in reversed(q):
        ls = sz[left[u]] if left[u] != -1 else 0
        rs = sz[right[u]] if right[u] != -1 else 0
        left_dp = dp[left[u]] if left[u] != -1 else 0
        right_dp = dp[right[u]] if right[u] != -1 else 0
        sz[u] = 1 + ls + rs
        dp[u] = min(
            rs + left_dp,
            ls + right_dp
        )

    print(dp[root])
