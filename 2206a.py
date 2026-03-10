n = int(input())
results = [1]
for current in range(2, n + 1):
    l, r = 0, current - 2
    while l <= r:
        mid = (l + r) // 2
        print('query', results[mid], current)
        ans = input()
        if ans == 'first':
            l = mid + 1
        else:
            r = mid - 1
    results = results[:l] + [current] + results[l:]

print('answer', *results)
