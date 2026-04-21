t = int(input())
for _ in range(t):
    n, x, y = map(int, input().split())
    s = input()
    p = list(map(int, input().split()))
    count_a = count_b = 0
    add_a = add_b = 0
    sub_a = sub_b = 0
    for i in range(n):
        if s[i] == '0':
            count_a += 1
            ai = p[i] // 2 + 1
            bi = p[i] - ai
            sub_b += bi
            if p[i] % 2 == 0:
                add_b += 1
        else:
            count_b += 1
            bi = p[i] // 2 + 1
            ai = p[i] - bi
            sub_a += ai
            if p[i] % 2 == 0:
                add_a += 1
        x -= ai
        y -= bi
    if x < 0 and sub_a + x < 0:
        print('NO')
        continue
    if y < 0 and sub_b + y < 0:
        print('NO')
        continue
    if count_a == 0:
        if x < 0:
            print('YES' if x + y >= 0 else 'NO')
        else:
            print('YES' if y >= (x - add_a) else 'NO')
        continue
    if count_b == 0:
        if y < 0:
            print('YES' if x + y >= 0 else 'NO')
        else:
            print('YES' if x >= (y - add_b) else 'NO')
        continue
    if x < 0 and y < 0:
        print('NO')
        continue
    if x >= 0 and y >= 0:
        print('YES')
        continue
    print('YES' if x + y >= 0 else 'NO')
