#!/usr/bin/env python

def gcd(x, y):
    while y != 0:
        r = x % y
        x = y
        y = r
    return x

a, b, c, d = map(int, raw_input().split())

mau2, tu2, chiamau, chiatu = d * a * b, c * a * b, d * a, c * b
#print tu2, mau2
#print chiatu, chiamau
if chiatu < chiamau:
    tu1, mau1 = a * chiatu, b * chiatu
else:
    tu1, mau1 = a * chiamau, b * chiamau
#print tu1, mau1
hieutu, hieumau = tu2 - tu1, mau2 - mau1
#print hieutu, hieumau
if hieutu == 0:
    tu = hieumau
    mau = mau2
else:
    tu = hieutu
    mau = tu2
#print tu, mau
z = gcd(tu, mau)
tu, mau = tu/z, mau/z
print "%s/%s" % (tu, mau)
