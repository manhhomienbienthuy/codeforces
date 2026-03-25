t = int(input())
for _ in range(t):
    n, x, y = map(int, input().split())
    p = list(map(int, input().split()))

    outer = p[:x] + p[y:]
    inner = p[x:y]

    min_val = min(inner)
    min_pos = inner.index(min_val)
    inner_min = inner[min_pos:] + inner[:min_pos]

    k = 0
    for k in range(len(outer)):
        if outer[k] >= min_val:
            break
    else:
        k += 1

    print(*outer[:k], *inner_min, *outer[k:])
