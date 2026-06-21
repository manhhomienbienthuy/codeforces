#!/usr/bin/env python3

def is_valid(r, k, new):
    if r[0] == new[0]:
        return False
    if r[1] == new[1]:
        return False
    if abs(r[0] - new[0]) == 2 and abs(r[1] - new[1]) == 1:
        return False
    if abs(r[0] - new[0]) == 1 and abs(r[1] - new[1]) == 2:
        return False
    if abs(k[0] - new[0]) == 2 and abs(k[1] - new[1]) == 1:
        return False
    if abs(k[0] - new[0]) == 1 and abs(k[1] - new[1]) == 2:
        return False
    return True

rook = [ord(c) for c in input()]
knight = [ord(c) for c in input()]
ok = 0
for i in range(ord('a'), ord('i')):
    for j in range(ord('1'), ord('9')):
        if is_valid(rook, knight, [i, j]):
            ok += 1
print(ok-1)
