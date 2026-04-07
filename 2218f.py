t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    n = x + y

    if n % 2 == 0:
        if x < 1 or x > n // 2:
            print("NO")
            continue
        k = 2 * x
    else:
        if x > (n - 1) // 2:
            print("NO")
            continue
        k = 2 * x + 1

    print("YES")
    for i in range(1, k):
        print(f"{i} {i + 1}")

    next_node = k + 1
    for _ in range((n - k) // 2):
        print(f"1 {next_node}")
        print(f"1 {next_node + 1}")
        next_node += 2
