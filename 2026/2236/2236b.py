t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()

    ok = True
    for start in range(k):
        cnt = 0
        i = start
        size = 0

        while i < n:
            if s[i] == '1':
                cnt += 1
            size += 1
            i += k

        if size == 1:
            if cnt == 1:
                ok = False
                break
        else:
            if cnt % 2 == 1:
                ok = False
                break

    print("YES" if ok else "NO")
