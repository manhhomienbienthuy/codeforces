def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    for i in range(n - k):
        if b[i] != -1 and b[i] != a[i]:
            print("NO")
            return
    for i in range(k, n):
        if b[i] != -1 and b[i] != a[i]:
            print("NO")
            return

    if n >= 2 * k:
        print("YES")
        return

    a_values = set(a[n - k : k])
    used = set()
    for i in range(n - k, k):
        if b[i] != -1:
            if b[i] not in a_values or b[i] in used:
                print("NO")
                return
            used.add(b[i])

    print("YES")

t = int(input())
for _ in range(t):
    solve()
