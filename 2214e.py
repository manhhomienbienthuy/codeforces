n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    adj[u].append((v, w))
    adj[v].append((u, w))

INF = 10 ** 9
dist = [INF] * (n + 1)
dist[1] = 0

for u in range(1, n + 1):
    for v, w in adj[u]:
        dist[v] = min(dist[v], dist[u] + w)

for i in range(2, n + 1):
    print(dist[i] if dist[i] != INF else -1)
