t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    S = [min(x % k, k - x % k) for x in map(int, input().split())]
    T = [min(x % k, k - x % k) for x in map(int, input().split())]
    print('YES' if sorted(S) == sorted(T) else 'NO')
