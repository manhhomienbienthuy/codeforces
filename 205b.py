n = int(input())
a = list(map(int, input().split()))

result = 0
for i in range(1, n):
    if a[i] < a[i-1]:
        result += a[i-1] - a[i]

print(result)
