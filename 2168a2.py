hexcode = '0123456789abcdefx'
alphabet = 'ghijklmnopqrstuvz'

encoding = str.maketrans(hexcode, alphabet)
decoding = str.maketrans(alphabet, hexcode)

phase = input()
if phase == 'first':
    n = int(input())
    a = map(int, input().split())
    s = []
    for x in a:
        y = str.translate(hex(x)[1:], encoding)
        s.append(y)
    print(''.join(s))
else:
    s = input().split('z')[1:]
    a = []
    for x in s:
        y = str.translate(x, decoding)
        y = int(y, 16)
        a.append(y)
    print(len(a))
    print(*a)
