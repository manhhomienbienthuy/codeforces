t = int(input())
for _ in range(t):
    n = int(input())
    l1 = input()
    l2 = input()
    result = 0
    i = 0
    while i < n:
        if i == n - 1:
            if l1[i] != l2[i]:
                result += 1
            break
        if l1[i] == l2[i]:
            i += 1
            continue
        if l1[i] == l1[i + 1]:
            if l2[i] != l2[i + 1]:
                result += 1
            i += 2
            continue
        result += 1
        i += 1
    print(result)
