t = int(input())
for _ in range(t):
    input()
    a = map(int, input().split())
    r = [0] * 3
    for x in a:
        r[x] += 1
    print(r[0] + min(r[1], r[2]) + abs(r[1] - r[2]) // 3)
  
