t = int(input())
for _ in range(t):
    n, x, s = map(int, input().split())
    u = input()

    ans = 0
    table = 0
    cnt_ae = 0
    for c in u:
        if ans == x * s:
            break

        if c == 'I':
            if table < x:
                table += 1
                ans += 1
            continue
        if c == 'E':
            if ans < table * s:
                ans += 1
            else:
                if cnt_ae > 0 and table < x:
                    cnt_ae -= 1
                    table += 1
                    ans += 1
            continue
        if ans < table * s:
            ans += 1
            cnt_ae += 1
        elif table < x:
            table += 1
            ans += 1

    print(ans)
