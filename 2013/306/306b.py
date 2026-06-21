n, m = map(int, input().split())
data = []
for i in range(m):
    x, y = map(int, input().split())
    data.append([x, x + y - 1, i + 1])

data = list(sorted(data, key=lambda x: x[0], reverse=True))
ans = []
while data:
    now = data.pop()
    while data and data[-1][0] == now[0]:
        if data[-1][1] > now[1]:
            ans.append(now[2])
            now = data.pop()
        else:
            ans.append(data[-1][2])
            data.pop()
    tmp = None
    while data and data[-1][0] <= now[1]:
        if data[-1][1] <= now[1]:
            ans.append(data[-1][2])
            data.pop()
        else:
            if tmp:
                if tmp[1] > data[-1][1]:
                    ans.append(data[-1][2])
                    data.pop()
                else:
                    ans.append(tmp[2])
                    tmp = data.pop()
            else:
                tmp = data.pop()
    if tmp:
        tmp[0] = now[1]+1
        data.append(tmp)
print(len(ans))
print(*ans)
