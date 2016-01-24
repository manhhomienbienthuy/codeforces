#!/usr/bin/env python3

import re
n = input()
for i in range(0, 1000, 8):
    regex = ".*".join(list(str(i)))
    if re.search(regex, n):
        print("YES")
        print(i)
        break
else:
    print("NO")
