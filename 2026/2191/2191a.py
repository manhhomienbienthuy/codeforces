t = int(input())
for j in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    odd = sorted(a[::2])
    even = sorted(a[1::2])
    m = min(odd[i + 1] - odd[i] for i in range((n - 1) // 2)) if n >= 3 else 2
    n = min(even[i + 1] - even[i] for i in range(n // 2 - 1)) if n >= 4 else 2
    print('NO' if min(m, n) == 1 else 'YES')
