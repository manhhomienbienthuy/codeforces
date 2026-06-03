import heapq

n = int(input())
a = list(map(int, input().split()))
pref = cnt = 0
heap = []
for x in a:
    pref += x
    heapq.heappush(heap, x)
    cnt += 1

    if pref < 0:
        y = heapq.heappop(heap)
        pref -= y
        cnt -= 1

print(cnt)
