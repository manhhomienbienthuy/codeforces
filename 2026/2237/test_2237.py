from math import gcd

with open("output.txt") as f:
    n = int(f.readline())
    nlist = f.readline()

x = (int)((n - 150) / 10 * 9)
print(f"""second
1
{x} {n}""")
num = list(map(int, nlist.split()))
for i in range(150, n):
    for j in range(150):
        print(gcd(num[i], num[j]))
