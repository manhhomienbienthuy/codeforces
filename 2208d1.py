import sys
from collections import deque
input = sys.stdin.readline
def solve():
    n = int(input())
    S = []
    for i in range(n):
        row = input().strip()
        S.append(row)
    # Build bitmask rows and columns
    R = [0] * n  # R[i] = bitmask of nodes reachable from i
    C = [0] * n  # C[j] = bitmask of nodes that can reach j
    for i in range(n):
        for j in range(n):
            if S[i][j] == '1':
                R[i] |= (1 << j)
                C[j] |= (1 << i)
    # Check reflexivity
    for i in range(n):
        if not (R[i] & (1 << i)):
            print("No")
            return
    # Check antisymmetry
    for i in range(n):
        for j in range(i + 1, n):
            if (R[i] & (1 << j)) and (R[j] & (1 << i)):
                print("No")
                return
    # Check transitivity: s[i][j]=1 => R[j] subset of R[i]
    for i in range(n):
        for j in range(n):
            if j != i and (R[i] & (1 << j)):
                if R[j] & ~R[i]:
                    print("No")
                    return
    # Extract Hasse diagram (covering relation)
    edges = []
    for i in range(n):
        for j in range(n):
            if i == j or not (R[i] & (1 << j)):
                continue
            common = R[i] & C[j]
            common &= ~(1 << i)
            common &= ~(1 << j)
            if common == 0:
                edges.append((i, j))
    if len(edges) != n - 1:
        print("No")
        return
    # Check connectivity (BFS on undirected graph)
    adj = [[] for _ in range(n)]
    for u, v in edges:
        adj[u].append(v)
        adj[v].append(u)
    vis = [False] * n
    q = deque([0])
    vis[0] = True
    cnt = 1
    while q:
        u = q.popleft()
        for v in adj[u]:
            if not vis[v]:
                vis[v] = True
                cnt += 1
                q.append(v)
    if cnt != n:
        print("No")
        return
    print("Yes")
    out = []
    for u, v in edges:
        out.append(f"{u + 1} {v + 1}")
    print('\n'.join(out))
t = int(input())
for _ in range(t):
    solve()
