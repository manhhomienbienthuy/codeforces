n = int(input())
a = sorted(map(int, input().split()))
s = 0
prev = -1
for i in range(n):
    if a[i] <= prev:
        s += prev + 1 - a[i]
    prev = max(prev + 1, a[i])

print(s)
