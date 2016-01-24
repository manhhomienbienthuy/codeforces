#!/usr/bin/env python3

n, p = map(int, input().split())
s = [c for c in input()]
tim(s[:], 0, n, p)

def tim(s, step, stop, limit):
    if step > stop:
        if palindrome(s):
            print(s)
            return 1
        return
    while ord(s[step]) < ord('a') + limit:
        s[step] = chr(ord(s[step])) + 1
        tim(s[:], step+1, stop, limit)
