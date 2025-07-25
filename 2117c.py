t = int(input())
for _ in range(t):
    n = int(input())
    a = input().split()
    result = 0
    cur_segment = last_segment = set()
    for x in a:
        cur_segment.add(x)
        last_segment.add(x)
        if cur_segment == last_segment:
            result += 1
            cur_segment = set()
    print(result)
