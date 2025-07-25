t = int(input())
for _ in range(t):
    s = int(input())
    a = int(s ** 0.5)
    print(-1 if a * a != s else f"0 {a}")
