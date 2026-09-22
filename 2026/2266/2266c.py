import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    x = y = 0
    for c in s:
        if c == s[0]:
            x += 1
        elif c > s[0]:
            y = max(x + 1, y + 1)
    print(n - max(x, y))
