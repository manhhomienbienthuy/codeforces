t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = "".join(input().split()).split("1")
    print(sum((len(s) + 1) // (k + 1) for s in a))
