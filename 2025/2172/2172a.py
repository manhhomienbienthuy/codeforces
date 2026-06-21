a = sorted(map(int, input().split()))
if a[-1] - a[0] >= 10:
    print('check again')
else:
    print('final', a[1])
