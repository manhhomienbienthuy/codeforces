t = int(input())
for _ in range(t):
    s = list(map(int, input().strip()))
    even = odd = 0
    for d in s:
        if d == 2:
            even += 1
        elif d & 1:
            odd = 1 + max(odd, even)
    print(len(s) - max(odd, even))
