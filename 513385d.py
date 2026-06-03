import heapq

t = int(input())
for _ in range(t):
    n, m, p = map(int, input().split())
    w = list(map(int, input().split()))

    g = [[] for _ in range(n)]
    for _ in range(m):
        a, b, s = map(int, input().split())
        a -= 1
        b -= 1
        g[a].append((b, s))

    dp = [{} for _ in range(n)]
    pq = []
    heapq.heappush(pq, (0, -p, 0, w[0]))
    dp[0][w[0]] = (0, p)

    def better(a, b):
        return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1])

    while pq:
        steps, nmoney, u, max_w = heapq.heappop(pq)
        money = -nmoney

        if u == n - 1:
            print(steps)
            break

        if max_w not in dp[u]:
            continue
        if dp[u][max_w] != (steps, money):
            continue

        for v, cost in g[u]:
            if max_w == 0 and money < cost:
                continue

            if money >= cost:
                k = 0
            else:
                k = (cost - money + max_w - 1) // max_w

            new_steps = steps + k
            new_money = money + k * max_w - cost
            new_max_w = max(max_w, w[v])
            state = (new_steps, new_money)

            if new_max_w not in dp[v] or better(state, dp[v][new_max_w]):
                dp[v][new_max_w] = state
                heapq.heappush(pq, (new_steps, -new_money, v, new_max_w))
    else:
        print(-1)
