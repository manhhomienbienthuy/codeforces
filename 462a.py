#!/usr/bin/env python3

def is_valid(s):
    for i in range(n):
        for j in range(n):
            cnt = 0
            # tren
            if i > 0 and s[i-1][j] == 'o':
                cnt += 1
            # duoi
            if i < n-1 and s[i+1][j] == 'o':
                cnt += 1
            # trai
            if j > 0 and s[i][j-1] == 'o':
                cnt += 1
            # phai
            if j < n-1 and s[i][j+1] == 'o':
                cnt += 1
            if cnt % 2:
                return False
    return True


n = int(input())
s = [[c for c in input()] for i in range(n)]
print("YES" if is_valid(s) else "NO")
