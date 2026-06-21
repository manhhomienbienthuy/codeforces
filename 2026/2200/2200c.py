import re

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    while re.search(r'([a-z])\1', s):
        s = re.sub(r'([a-z])\1', '', s)
    print('YES' if not s else 'NO')
