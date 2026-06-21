#!/usr/bin/env python3

def is_valid(ls, n):
    for x in ls:
        if x - n == 1 or x - n == -1:
            return False
    else:
        return True

n = int(input())
a = map(int, input().split())
