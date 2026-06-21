t = int(input())
for _ in range(t):
    n = int(input())
    for i in range(1, 2 * n - 3, 2):
        print('?', i, i + 1, flush=True)
        ans = input()
        if ans == '1':
            print('!', i)
            break
    else:
        print('?', 2 * n - 3, 2 * n - 2)
        ans = input()
        if ans == '1':
            print('!', 2 * n - 3)
            continue
        print('?', 2 * n - 2, 2 * n - 1)
        ans = input()
        if ans == '1':
            print('!', 2 * n - 2)
            continue
        print('?', 2 * n - 3, 2 * n - 1)
        ans = input()
        if ans == '1':
            print('!', 2 * n - 3)
            continue
        print('!', 2 * n)
