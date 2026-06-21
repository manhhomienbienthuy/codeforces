for t in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    d = list(map(int, input().split()))
    q = []
    for i in range(n):
        j = i - 1
        while d[n - i - 1] > 0:
            if j < 0:
                print(-1)
                break
            if q[j] > p[n - i - 1]:
                d[n - i - 1] -= 1
            j -= 1
        else:
            q = q[:j+1] + [p[n - i - 1]] + q[j+1:]
            continue
        break
    else:
        print(q)
        print(*[q.index(i) + 1 for i in p])
