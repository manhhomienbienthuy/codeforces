#!/usr/bin/env python3

w, h = map(int, input().split())

w_edge = h_edge = 0
for i in range(2, w + 1, 2):
    w_edge += (w - i + 1)
for i in range(2, h + 1, 2):
    h_edge += (h - i + 1)
print(w_edge * h_edge)
