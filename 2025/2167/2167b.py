t = int(input())
for _ in range(t):
    input()
    s, t = input().split()
    print(('no', 'yes')[sorted(s) == sorted(t)])
