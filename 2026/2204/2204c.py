from math import lcm

t = int(input())
for _ in range(t):
    times = [0] * 3
    *times, m = map(int, input().split())
    ab = lcm(times[0], times[1])
    bc = lcm(times[1], times[2])
    ac = lcm(times[0], times[2])
    abc = lcm(*times)
    result = [m // abc * 2] * 3
    count = [m // times[i] - m // abc for i in range(3)]
    if ab != abc:
        cnt = m // ab - m // abc
        result[0] += cnt * 3
        result[1] += cnt * 3
        count[0] -= cnt
        count[1] -= cnt
    if ac != abc:
        cnt = m // ac - m // abc
        result[0] += cnt * 3
        result[2] += cnt * 3
        count[0] -= cnt
        count[2] -= cnt
    if bc != abc:
        cnt = m // bc - m // abc
        result[1] += cnt * 3
        result[2] += cnt * 3
        count[1] -= cnt
        count[2] -= cnt
    for i in range(3):
        result[i] += count[i] * 6
    print(*result)
