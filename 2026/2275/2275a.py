import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    x, y, r = map(int, input().split())
    print(x, y + r)
