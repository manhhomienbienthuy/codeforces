import heapq

INF = 10**18

N = int(input())

P = [list(map(int, input().split())) for _ in range(N)]
R = [list(map(int, input().split())) for _ in range(N)]
D = [list(map(int, input().split())) for _ in range(N-1)]

# dp[i][j] = dict: max_p -> (actions, money)
dp = [[dict() for _ in range(N)] for _ in range(N)]

pq = []
# (actions, -money, i, j, max_p)
heapq.heappush(pq, (0, 0, 0, 0, P[0][0]))

dp[0][0][P[0][0]] = (0, 0)

def better(a, b):
    # compare (actions, money)
    return a[0] < b[0] or (a[0] == b[0] and a[1] > b[1])

while pq:
    actions, neg_money, i, j, max_p = heapq.heappop(pq)
    money = -neg_money

    if (i, j) == (N-1, N-1):
        print(actions)
        break

    if max_p not in dp[i][j]:
        continue
    if dp[i][j][max_p] != (actions, money):
        continue

    # try Right
    if j < N-1:
        cost = R[i][j]
        if money >= cost:
            k = 0
        else:
            k = (cost - money + max_p - 1) // max_p

        new_actions = actions + k + 1
        new_money = money + k * max_p - cost
        new_max_p = max(max_p, P[i][j+1])

        state = (new_actions, new_money)

        if new_max_p not in dp[i][j+1] or better(state, dp[i][j+1][new_max_p]):
            dp[i][j+1][new_max_p] = state
            heapq.heappush(pq, (new_actions, -new_money, i, j+1, new_max_p))

    # try Down
    if i < N-1:
        cost = D[i][j]
        if money >= cost:
            k = 0
        else:
            k = (cost - money + max_p - 1) // max_p

        new_actions = actions + k + 1
        new_money = money + k * max_p - cost
        new_max_p = max(max_p, P[i+1][j])

        state = (new_actions, new_money)

        if new_max_p not in dp[i+1][j] or better(state, dp[i+1][j][new_max_p]):
            dp[i+1][j][new_max_p] = state
            heapq.heappush(pq, (new_actions, -new_money, i+1, j, new_max_p))
