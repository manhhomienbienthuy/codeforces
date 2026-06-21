n = int(input())

positions = [0] * (n + 2)
positions[n] = 1
results = [n + 1, n] + [0] * n

def check(x, y):
    print(f"query {x} {y}")
    return input() == "first"

def insert(pos, val):
    for i in range(val + 1, n + 1):
        if positions[i] >= pos:
            positions[i] += 1
    max_rank = n - val
    for i in range(max_rank, pos - 1, -1):
        results[i + 1] = results[i]
    results[pos] = val
    positions[val] = pos

for i in range(n - 1, 0, -1):
    pass_len = n - i
    candidates = [0, 1]

    for j in range(2, pass_len + 1):
        left_next = positions[results[j - 1] + 1] if results[j - 1] + 1 <= n + 1 else 0
        right_next = positions[results[j] + 1] if results[j] + 1 <= n + 1 else 0
        pos_next = positions[i + 1]
        if left_next > right_next and (left_next < pos_next or pos_next < right_next):
            candidates.append(j)
        elif left_next < right_next and left_next < pos_next and pos_next < right_next:
            candidates.append(j)

    if candidates[-1] != pass_len:
        candidates.append(pass_len)

    l, r = 1, len(candidates) - 1
    candidates.append(pass_len + 1)
    check_flag = False
    while l <= r:
        mid = (l + r) // 2
        if check(results[candidates[mid]], i):
            check_flag = True
            l = mid + 1
        else:
            r = mid - 1
    insert_pos = candidates[l] - 1

    if insert_pos == candidates[l - 1] and check_flag:
        insert_pos += 1
    elif insert_pos == 0 or check(results[insert_pos], i):
        insert_pos += 1
    else:
        l, r = 1, pass_len
        while l <= r:
            mid = (l + r) // 2
            if check(results[mid], i):
                l = mid + 1
            else:
                r = mid - 1
        insert_pos = l

    insert(insert_pos, i)


print("answer", *results[1:-1])
