t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = map(int, input().split())
    cnt = [0] * (n + 1)
    for x in a:
        cnt[x] += 1
    pref = [0] * (n + 1)
    for i in range(1, n + 1):
        pref[i] = pref[i - 1] + cnt[i]
    for i in range(n, 1, -1):
        s = pref[min(n, 4 * i - 1)] - cnt[i]
        if 2 * i <= n:
            s -= cnt[2 * i]
        if 3 * i <= n:
            s -= cnt[3 * i]
        if s <= k:
            print(i)
            break
    else:
        print(1)
