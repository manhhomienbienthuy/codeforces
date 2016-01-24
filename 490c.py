#!/usr/bin/env python

s = raw_input()
a, b = map(int, raw_input().split())
v = [0]

def is_valid(y=0L, q=1L):
    for i in s[::-1]:
        v.append((v[-1] + q * (ord(i) & 15)) % b)
        q = q * 10 % b
    for x in range(1, len(s)):
        y = (10 * y + ord(s[x-1]) - 48) % a
        if y + v[~x] < 1 and '0' < s[x]:
            return x
    return None

x = is_valid()
if x:
    print("YES")
    print(s[:x])
    print(s[x:])
else:
    print("NO")
