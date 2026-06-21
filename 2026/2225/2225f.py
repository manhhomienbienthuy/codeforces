class Hash:
    def __init__(self, s):
        self.n = len(s)

        self.base1 = 91138233
        self.base2 = 97266353
        self.mod1 = 10**9 + 7
        self.mod2 = 10**9 + 9

        self.h1 = [0] * (self.n + 1)
        self.h2 = [0] * (self.n + 1)
        self.p1 = [1] * (self.n + 1)
        self.p2 = [1] * (self.n + 1)

        for i, ch in enumerate(s):
            x = ord(ch)
            self.h1[i + 1] = (self.h1[i] * self.base1 + x) % self.mod1
            self.h2[i + 1] = (self.h2[i] * self.base2 + x) % self.mod2
            self.p1[i + 1] = (self.p1[i] * self.base1) % self.mod1
            self.p2[i + 1] = (self.p2[i] * self.base2) % self.mod2

    def get(self, l, r):
        x1 = (self.h1[r] - self.h1[l] * self.p1[r - l]) % self.mod1
        x2 = (self.h2[r] - self.h2[l] * self.p2[r - l]) % self.mod2
        return (x1, x2)

def lcp(rh, i, j, max_len):
    lo, hi = 0, max_len
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if rh.get(i, i + mid) == rh.get(j, j + mid):
            lo = mid
        else:
            hi = mid - 1
    return lo


t = int(input())
for _ in range(t):
    n, l, k = map(int, input().split())
    s = input()

    limit = n - k * l
    if limit < 0:
        print("NO")
        continue

    if k == 1:
        print("YES")
        print(s)
        continue

    rh = Hash(s)

    result = 0
    result_len = l + limit

    for i in range(l, n - l + 1, l):
        upper = min(i + limit + 1, n - l + 1)
        for j in range(i, upper):
            cur_len = l + limit - (j % l)
            cmp_len = min(
                result_len,
                cur_len,
                n - result,
                n - j
            )


            c = lcp(rh, result, j, cmp_len)
            if c < cmp_len and s[j + c] > s[result + c]:
                result = j
                result_len = cur_len

    print("YES")
    print(s[result : result + result_len])
