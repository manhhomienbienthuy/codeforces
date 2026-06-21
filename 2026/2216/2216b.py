t = int(input())
for _ in range(t):
    t, h, u = map(int, input().split())
    tu = min(t, u)
    t -= tu
    u -= tu
    tht = min(t // 2, h)
    t -= tht * 2
    h -= tht
    th = min(t, h)
    t -= th
    h -= th
    result = tu * 4 + tht * 7 + th * 5 + (h + u) * 3 + 2 * t + (t > 0)
    print(result)
