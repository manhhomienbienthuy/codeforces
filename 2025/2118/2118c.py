t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    res = 0
    for i in range(65):
        b = 1 << i
        for x in a:
            if x & b == 0 and k >= b:
                k -= b
                x += b
            if x & b:
                res += 1
    print(res)
