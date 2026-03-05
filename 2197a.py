def calc_d(n):
    result = 0
    while n > 0:
        result += n % 10
        n //= 10
    return result

t = int(input())
for _ in range(t):
    x = int(input())
    count = 0
    for d in range(82):
        if calc_d(x + d) == d:
            count += 1
    print(count)
