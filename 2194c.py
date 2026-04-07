t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    C = [0] * n
    for i in range(k):
        strip = input()
        for j in range(n):
            C[j] |= 1 << (ord(strip[j]) - 97)

    for d in range(1, n + 1):
        if n % d:
            continue

        ok = True
        chars = ['*'] * d
        for r in range(d):
            intersection = (1 << 26) - 1
            i = r
            while i < n:
                intersection &= C[i]
                i += d
            if intersection == 0:
                ok = False
                break
            bit = intersection.bit_length() - 1
            chars[r] = chr(97 + bit)

        if ok:
            print(''.join(chars[i % d] for i in range(n)))
            break
