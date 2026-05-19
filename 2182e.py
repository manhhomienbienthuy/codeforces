import heapq

t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    box = sorted(map(int, input().split()))

    friend = []
    happy = [False] * n
    money = 0

    for _ in range(n):
        x, y, z = map(int, input().split())
        money += y
        friend.append((x, z - y))

    r = k - money
    if r < 0:
        print(0)
        continue

    friend = sorted(friend)
    heap = []
    i = 0
    ans = 0

    for b in box:
        while i < n and not happy[i] and friend[i][0] <= b:
            heapq.heappush(heap, (-friend[i][1], i))
            i += 1
        while heap and happy[heap[0][1]]:
            heapq.heappop(heap)
        if heap:
            x, y = heapq.heappop(heap)
            happy[y] = True
            ans += 1

    u = sorted(friend[i][1] for i in range(n) if not happy[i])
    for x in u:
        if r >= x:
            r -= x
            ans += 1
        else:
            break

    print(ans)
