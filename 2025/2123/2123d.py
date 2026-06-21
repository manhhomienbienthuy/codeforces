t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = sum(int(x) for x in input())
    if s <= k or n // 2 < k:
        print("Alice")
    else:
        print("Bob")
