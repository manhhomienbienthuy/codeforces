t = int(input())

def step(a, b):
    if a == b:
        return 0
    if a < b:
        return 2 - (a - b) % 2
    return 1 + ((a - b) % 2)

for _ in range(t):
    a, b = map(int, input().split())
    print(step(a, b))
