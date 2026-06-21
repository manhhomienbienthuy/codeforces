t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    cnt1 = s.count('1')
    cnt0 = n - cnt1
    if cnt0 & 1:
        print(cnt0)
        if cnt0:
            print(*(i + 1 for i in range(n) if s[i] == '0'))
        continue
    if 1 ^ (cnt1 & 1):
        print(cnt1)
        if cnt1:
            print(*(i + 1 for i in range(n) if s[i] == '1'))
        continue
    print(-1)
