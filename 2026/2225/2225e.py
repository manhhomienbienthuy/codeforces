from math import sqrt

n, r = list(map(int, input().split()))
points = [tuple(map(int, input().split())) for _ in range(n)]

dx = 2 * r
dy = sqrt(3) * r

circles = set()
covered = set()

for i, (px, py) in enumerate(points):
    row = round(py / dy)

    for rr in [row, row + 1]:
        y = rr * dy
        x_offset = 0 if rr % 2 == 0 else r
        col = round((px - x_offset) / dx)

        for cc in [col, col + 1]:
            cx = cc * dx + x_offset
            cy = y

            if (px - cx) ** 2 + (py - cy) ** 2 <= r * r:
                circles.add((round(cx), round(cy)))
                covered.add(i)
                break

    if len(covered) * 100 >= 89 * len(points):
        break

print(len(circles))
for c in circles:
    print(*c)
