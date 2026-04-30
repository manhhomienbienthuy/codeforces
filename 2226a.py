MOD = 676767677

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    result = a[n - 1] == 1
    result += sum(x for x in a if x > 1)
    print(result % MOD)
