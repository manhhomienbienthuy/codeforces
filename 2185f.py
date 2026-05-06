t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    cur = a[:]
    pref = [cur]
    for i in range(n - 1):
        cur = [cur[i] ^ cur[i + 1] for i in range(0, 1 << (n - i), 2)]
        pref.append(cur)

    for _q in range(q):
        ans = 0
        b, c = map(int, input().split())
        b -= 1
        mask = a[b] ^ c
        for i in range(n):
            x = pref[i][b] ^ mask
            if b & 1:
                enemy = b - 1
                if x <= pref[i][enemy]:
                    ans += 1 << i
            else:
                enemy = b + 1
                if x < pref[i][enemy]:
                    ans += 1 << i
            b >>= 1
        print(ans)
