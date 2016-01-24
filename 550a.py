#!/usr/bin/env python3

s = input()
l1 = s.find("AB")
r1 = s.rfind("BA")
l2 = s.find("BA")
r2 = s.rfind("AB")

if (l1 >= 0 and r1 >= 0 and (l1 - r1 > 1 or l1 - r1 < -1)) or (l2 >= 0 and r2 >= 0 and (l2 - r2 > 1 or l2 - r2 < -1)):
    print("YES")
else:
    print("NO")
