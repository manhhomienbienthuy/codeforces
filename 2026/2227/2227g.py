import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    # Build signed array
    d = [0] * (n + 1)
    for i in range(1, n + 1):
        d[i] = a[i-1] if i % 2 == 1 else -a[i-1]

    # Prefix sums
    pref = [0] * (n + 1)
    for i in range(1, n + 1):
        pref[i] = pref[i-1] + d[i]

    # Length-1 subarrays
    ans = n

    # Coordinate compression
    vals = sorted(set(pref))
    comp = {v: i+1 for i, v in enumerate(vals)}
    size = len(vals) + 2

    class Fenwick:
        def __init__(self):
            self.bit = [10**18] * size
        def update(self, i, v):
            while i < size:
                self.bit[i] = min(self.bit[i], v)
                i += i & -i
        def query(self, i):
            res = 10**18
            while i > 0:
                res = min(res, self.bit[i])
                i -= i & -i
            return res

    # Even / odd parity handled separately
    for parity in (0, 1):
        fw = Fenwick()
        indices = list(range(parity, n+1, 2))

        fw.update(comp[pref[indices[0]]], pref[indices[0]])

        for j in indices[1:]:
            pj = pref[j]
            if fw.query(comp[pj]) < pj:
                ans += 1
            fw.update(comp[pj], pj)

    print(ans)
