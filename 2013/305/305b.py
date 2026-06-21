p, q = map(int, raw_input().split(' '))
n = int(raw_input())
a = map(int, raw_input().split(' '))

x, y = a[n - 1], 1
for i in reversed(range(n-1)):
    x, y = y, x
    x += a[i] * y

if x * q == y * p:
    print "YES"
else:
    print "NO"
