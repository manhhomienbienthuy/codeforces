n, p, q = map(int, input().split())
s = input()
for i in range(n // p + 1):
    for j in range(n // q + 1):
        if n == p * i + q * j:
            print(i + j)
            if i > 0:
                print("\n".join((s[k*p:(k+1)*p] for k in range(i))))
            if j > 0:
                print("\n".join((s[p*i+k*q:p*i + (k+1)*q] for k in
                                 range(j))))
            exit()
print(-1)
