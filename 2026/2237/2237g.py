from math import lcm

LIMIT = 10**6

phase = input()
if phase == 'first':
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = []
        cur = 1
        for x in a:
            l = lcm(cur, x)
            if l > LIMIT:
                b.append(cur)
                cur = x
            else:
                cur = l
        b.append(cur)
        print(len(b) + n)
        print(*b, *a)
else:
    t = int(input())
    for _ in range(t):
        n, k = map(int, input().split())
        groups = k - n
        a = [-1] * n
        idx = 1
        l = 1
        i = 0
        while i < n:
            print(f"? {idx} {i + groups + 1}")
            g = int(input())
            l = lcm(l, g)
            if l > LIMIT:
                l = 1
                idx += 1
            else:
                a[i] = g
                i += 1

        print("!", *a)
