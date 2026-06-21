t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    a = [i for i in range(n) if s[i] == 'a']
    a = sorted(a[i] - i for i in range(len(a)))
    b = [i for i in range(n) if s[i] == 'b']
    b = sorted(b[i] - i for i in range(len(b)))
    if not a or not b:
        print(0)
    else:
        mid_a = a[len(a) // 2]
        mid_b = b[len(b) // 2]
        a = sum(abs(i - mid_a) for i in a)
        b = sum(abs(i - mid_b) for i in b)
        print(min(a, b))
