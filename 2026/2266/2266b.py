import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    a, b, c = map(int, input().split())
    if a >= b:
        print(a + c - b)
    else:
        print(max(abs(a + c - b), b - a))
