t = int(input())
for _ in range(t):
    n = int(input())
    first = (1, 9, 29, 56)
    if n < 5:
        print(first[n - 1])
        continue
    print(5 * (n * n - n - 1))
