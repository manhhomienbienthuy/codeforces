t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    s = a + b + c
    q, r = divmod(s, 3)
    print(q % 20260401 + r)
