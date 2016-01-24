#!/usr/bin/env python3

import sys

x1, y1, x2, y2 = map(int, input().split())
if x1 == x2:
    x3, y3, x4, y4 = x1+abs(y1-y2), y1, x2+abs(y1-y2), y2
elif y1 == y2:
    x3, y3, x4, y4 = x1, y1+abs(x1-x2), x2, y2+abs(x1-x2)
else:
    if abs(x1-x2) == abs(y1-y2):
        x3, y3, x4, y4 = x1, y2, x2, y1
    else:
        print(-1)
        sys.exit(0)
print(x3, y3, x4, y4)
