#!/usr/bin/env python

x = input()
result = 0

for i in xrange(5, 0, -1):
    result += x / i
    x %= i
print result
