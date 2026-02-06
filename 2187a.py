def can_sort_with_k(a, k):
    n = len(a)
    if n <= 1:
        return True

    # Create adjacency list for elements that can be swapped
    adj = [[] for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            if abs(a[i] - a[j]) >= k:
                adj[i].append(j)
                adj[j].append(i)

    # Find connected components using DFS
    visited = [False] * n
    components = []

    def dfs(node, component):
        visited[node] = True
        component.append(node)
        for neighbor in adj[node]:
            if not visited[neighbor]:
                dfs(neighbor, component)

    for i in range(n):
        if not visited[i]:
            component = []
            dfs(i, component)
            components.append(component)

    # Check if array can be sorted
    sorted_a = sorted(a)
    for component in components:
        # Get values in this component
        component_values = [a[i] for i in component]
        component_values.sort()

        # Get target values for positions in this component
        component_positions = sorted(component)
        target_values = [sorted_a[i] for i in component_positions]

        # Check if they match
        if component_values != target_values:
            return False

    return True

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    # If array is already sorted, return -1
    if a == sorted(a):
        return -1

    # Binary search for the maximum k
    left, right = 1, max(a) - min(a)
    result = -1

    while left <= right:
        mid = (left + right) // 2
        if can_sort_with_k(a, mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1

    return result

t = int(input())
for _ in range(t):
    print(solve())
