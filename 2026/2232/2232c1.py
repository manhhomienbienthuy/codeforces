t = int(input())
for _ in range(t):
    n, x, s = map(int, input().split())
    u = input()
    ans = 0
    for k in range(x + 1):
        table = 0
        seated = 0
        ai = 0

        for c in u:
            if seated == x * s:
                break
            if c == 'I' or (c == 'A' and ai < k):
                if table < x:
                    table += 1
                    seated += 1
                    ai += c == 'A'
                continue
            if seated < table * s:
                seated += 1

        ans = max(ans, seated)

    print(ans)
