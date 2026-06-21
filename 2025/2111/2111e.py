def idx(c):
    return ord(c) - 97

def b_to_a():
    global fb, fc, cnt_bc, cnt_cb, cnt_bca, cnt_cba
    if cnt_bca > 0:
        cnt_bca -= 1
        cnt_bc += 1
        c_to_a()
    elif cnt_cb > 0 and fc > -1 and (fc < fb or fb == -1):
        cnt_cb -= 1
        cnt_cba += 1
        fc = next_pos[fc + 1][2]
    elif fb != -1:
        fb = next_pos[fb + 1][1]

def c_to_a():
    global fb, fc, cnt_bc, cnt_cb, cnt_bca, cnt_cba
    if cnt_cba > 0:
        cnt_cba -= 1
        cnt_cb += 1
        b_to_a()
    elif cnt_bc > 0 and fb > - 1 and (fb < fc or fc == -1):
        cnt_bc -= 1
        cnt_bca += 1
        fb = next_pos[fb + 1][1]
    elif fc != -1:
        fc = next_pos[fc + 1][2]

t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    s = input()

    next_pos = [[-1] * 3 for _ in range(n + 1)]
    for i in range(n - 1, -1, -1):
        for c in range(3):
            next_pos[i][c] = next_pos[i + 1][c]
        next_pos[i][idx(s[i])] = i

    fb, fc = next_pos[0][1], next_pos[0][2]
    cnt_bc = cnt_cb = cnt_bca = cnt_cba = 0

    for i in range(q):
        x, y = map(lambda x: ord(x) - 97, input().split())

        if (x, y) == (1, 0):
            b_to_a()
        elif (x, y) == (2, 0):
            c_to_a()
        elif (x, y) == (1, 2):
            cnt_bc += 1
        elif (x, y) == (2, 1):
            cnt_cb += 1

    for i in range(n):
        if s[i] == 'a':
            print('a', end='')
        elif s[i] == 'b':
            if fb == -1 or i < fb:
                print('a', end= '')
            else:
                print('b', end='')
        else:
            if fc == -1 or i < fc:
                print('a', end='')
            else:
                if cnt_cb > 0:
                    print('b', end='')
                    cnt_cb -= 1
                else:
                    print('c', end='')
    print()
