t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    grid = []
    for i in range(n):
        row = list(map(int, input().split()))
        grid.append(row)

    prefix = []
    total = 0
    for i in range(n):
        prow = [0] * (m + 1)
        for j in range(m):
            prow[j + 1] = prow[j] + grid[i][j]
        prefix.append(prow)
        total += prow[m]

    INF = 300000

    lo = [[INF] * (m + 1) for _ in range(n + 1)]
    hi = [[-INF] * (m + 1) for _ in range(n + 1)]
    lo[0][0] = hi[0][0] = 0

    for i in range(n + 1):
        for j in range(m + 1):
            if lo[i][j] > hi[i][j]:
                continue
            if j < m:
                if lo[i][j] < lo[i][j + 1]:
                    lo[i][j + 1] = lo[i][j]
                if hi[i][j] > hi[i][j + 1]:
                    hi[i][j + 1] = hi[i][j]
            if i < n:
                val_lo = lo[i][j] + prefix[i][j]
                val_hi = hi[i][j] + prefix[i][j]
                if val_lo < lo[i + 1][j]:
                    lo[i + 1][j] = val_lo
                if val_hi > hi[i + 1][j]:
                    hi[i + 1][j] = val_hi

    rlo = [[INF] * (m + 1) for _ in range(n + 1)]
    rhi = [[-INF] * (m + 1) for _ in range(n + 1)]
    rlo[n][m] = rhi[n][m] = 0

    for i in range(n, -1, -1):
        for j in range(m, -1, -1):
            if i == n and j == m:
                continue
            if j < m and rlo[i][j + 1] <= rhi[i][j + 1]:
                if rlo[i][j + 1] < rlo[i][j]:
                    rlo[i][j] = rlo[i][j + 1]
                if rhi[i][j + 1] > rhi[i][j]:
                    rhi[i][j] = rhi[i][j + 1]
            if i < n and rlo[i + 1][j] <= rhi[i + 1][j]:
                val_lo = prefix[i][j] + rlo[i + 1][j]
                val_hi = prefix[i][j] + rhi[i + 1][j]
                if val_lo < rlo[i][j]:
                    rlo[i][j] = val_lo
                if val_hi > rhi[i][j]:
                    rhi[i][j] = val_hi

    best_lo = lo[n][m]
    best_hi = hi[n][m]
    half = total / 2.0
    if half < best_lo:
        target = best_lo
    elif half > best_hi:
        target = best_hi
    else:
        a1 = int(half)
        a2 = a1 + 1
        if a1 < best_lo:
            a1 = best_lo
        if a2 > best_hi:
            a2 = best_hi
        if a1 * (total - a1) >= a2 * (total - a2):
            target = a1
        else:
            target = a2

    path = []
    cur = 0
    i, j = 0, 0
    while i < n or j < m:
        can_d = False
        can_r = False
        if i < n:
            new_cur = cur + prefix[i][j]
            need = target - new_cur
            if rlo[i + 1][j] <= need <= rhi[i + 1][j]:
                can_d = True
        if j < m:
            need = target - cur
            if rlo[i][j + 1] <= need <= rhi[i][j + 1]:
                can_r = True

        if can_d:
            path.append('D')
            cur += prefix[i][j]
            i += 1
        elif can_r:
            path.append('R')
            j += 1
        else:
            break

    product = target * (total - target)
    print(product)
    print(''.join(path))
