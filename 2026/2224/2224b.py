t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = set(a)
    mex = 0
    while mex in s:
        mex += 1
    m = max(a)
    ans = n * m + mex * (n - 1) - (mex * (mex - 1))//2
    if m == mex - 1:
        ans += 1
    print(ans)
