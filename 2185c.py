t = int(input())
for _ in range(t):
    input()
    a = sorted(set(map(int, input().split())))
    m, l = 1, 1
    for i in range(1, len(a)):
        if a[i] - a[i - 1] == 1:
            l += 1
        else:
            if l > m:
                m = l
            l = 1
    print(max(m, l))
