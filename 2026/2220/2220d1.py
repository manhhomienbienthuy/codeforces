t = int(input())
for _ in range(t):
    n = int(input())
    answers = {
        0: 0,
        2 * n + 1: 3,
    }

    def ask(a):
        if len(a) == 1:
            return 1
        print('?', len(a), *[x + 1 for x in a])
        return int(input())

    def query(mid):
        if mid in answers:
            return answers[mid]
        x = ask(range(mid))
        y = ask(range(mid, 2 * n + 1))
        if x == y:
            if (mid - x ) % 2:
                answers[mid] = 3
                return 3
            answers[mid] = 0
            return 0
        if x > y:
            answers[mid] = 1
            return 1
        answers[mid] = 2
        return 2

    result = []
    for found in range(3):
        l, r = 0, 2 * n + 1
        while l < r - 1:
            mid = (l + r) // 2
            x = query(mid)
            if x > found:
                r = mid
            else:
                l = mid
        result.append(r)
    print('!', *result)
