x, y = map(int, input().split())

result = []
flag = "A"
while x * y > 1:
   print(x, y)
   k = min(x // y, x - 1)
   if k > 0:
      result.append("%d%c" % (k, flag))
   x, y = y, x - k * y
   flag = "A" if flag == "B" else "B"

if x == 0 or y == 0:
   print("Impossible")
else:
   print("".join(result))
