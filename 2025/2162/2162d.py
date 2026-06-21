def ask(a, b):
    print(f'1 {a} {b}')
    sa = int(input())
    print(f'2 {a} {b}')
    sp = int(input())
    return sp - sa

t = int(input())
for _ in range(t):
    n = int(input())
    length = ask(1, n)
    l, r = 1, n
    while r - l + 1 > length:
        mid = (l + r) // 2
        d = ask(l, mid)
        if d == 0:
            l = mid + 1
        elif d == length:
            r = mid
        else:
            l = mid - d + 1
            r = l + length - 1
    print(f'! {l} {r}')
