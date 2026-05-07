t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    b = input()
    level_a = level_b = 0
    for i in range(n):
        if a[i] == b[i] == '(':
            level_a += 1
            level_b += 1
        elif a[i] == b[i] == ')':
            level_a -= 1
            level_b -= 1
        else:
            if level_a == level_b == 0:
                print('NO')
                break
            if level_a <= level_b:
                level_a += 1
                level_b -= 1
            else:
                level_a -= 1
                level_b += 1
        if level_a < 0 or level_b < 0:
            print('NO')
            break
    else:
        if level_a == level_b == 0:
            print('YES')
        else:
            print('NO')
