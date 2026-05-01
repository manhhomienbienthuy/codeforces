t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    print(('NO', 'YES')[s.count('(') * 2 == n])
