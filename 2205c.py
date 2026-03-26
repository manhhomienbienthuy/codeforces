t = int(input())

for _ in range(t):
    n = int(input())
    Q = []
    blogs = []
    for i in range(n):
        a = list(map(int, input().split()))[1:]
        a = list(dict.fromkeys(a).keys())
        blogs.append(a[::-1])
    while blogs:
        b = min(blogs)
        Q += b
        for i in range(len(blogs)):
            blogs[i] = [k for k in blogs[i] if k not in Q]
        blogs = [k for k in blogs if k]
    print(*Q)
