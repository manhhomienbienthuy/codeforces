#!/usr/bin/env python

s = raw_input ()
res = ""
res += (s[len (s) - 1]);
for i in range (1, len (s)):
    if (s[len (s) - i - 1] >= res[0]):
        res = ((s[len (s) - i - 1])) + res
print res
