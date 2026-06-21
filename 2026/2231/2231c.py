for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    prev = None
    for x in a:
        if x == 1:
            cur = {1: 0, 2: 1}
        else:
            step = 0
            y = x
            cur = {}
            while True:
                cur[y] = step
                if y == 1:
                    break
                step += 1
                if y & 1:
                    y += 1
                else:
                    y //= 2
        if prev is None:
            prev = cur
        else:
            new_prev = {}
            for v, step in cur.items():
                if v in prev:
                    new_prev[v] = prev[v] + step

            prev = new_prev
    print(min(prev.values()))
