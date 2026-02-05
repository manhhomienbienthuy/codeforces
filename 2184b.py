t = int(input())
for _ in range(t):
    s, k, m = map(int, input().split())
    mm = min(s, k)
    q, r = divmod(m, k)
    if q & 0x1:
        print(max(mm - r, 0))
    else:
        print(max(0, s - r))
