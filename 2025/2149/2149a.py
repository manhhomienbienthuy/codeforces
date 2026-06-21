t = int(input())
for _ in range(t):
    n = int(input())
    a = input().split()
    print(2 * (a.count('-1') % 2) + a.count('0'))
