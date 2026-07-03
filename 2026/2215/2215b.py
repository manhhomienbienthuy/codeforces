from math import isqrt

t = int(input())
for _ in range(t):
    n = int(input())

    d = []
    for i in range(1, isqrt(n) + 1):
        if (n % i == 0):
            d.append(i)
            if (i * i != n):
                d.append(n // i)

    def find_b(s, p):
        if p == 2:
            return s - 1 if s > 2 else -1

        lo = 2
        hi = s ** (1.0 / (p - 1)) + 3
        while lo <= hi:
            mid = (lo + hi) // 2
            val = (mid ** p - 1) // (mid - 1)
            if val == s:
                return mid
            elif val < s:
                lo = mid + 1
            else:
                hi = mid - 1

        return -1

    def check(m, b, p):
        base = b ** p
        while m > 0:
            if m % base >= b:
                return False
            m //= base

        return True

    ans = 0
    for s in d:
       if s < 3:
          continue
       m = n // s
       for p in range(2, 41):
           if (1 << p) > s + 1:
               break
           b = find_b(s, p)
           ans += (b >= 2) and check(m, b, p)
    print(ans)
