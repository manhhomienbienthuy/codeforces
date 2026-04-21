alphabet = 'abcdefghijklmnopqrstuvwxyz'
phase = input()
if phase == 'first':
    n = int(input())
    s = map(lambda x: alphabet[int(x) - 1], input().split())
    print(''.join(s))
else:
    s = list(map(lambda x: alphabet.index(x) + 1, input()))
    print(len(s))
    print(*s)
