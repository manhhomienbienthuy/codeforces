import sys

MOD = 10**9 + 7

def solve():
    input = sys.stdin.readline
    t = int(input())

    for _ in range(t):
        n, c = map(int, input().split())
        w = input().strip()

        # mex=1 must exist → otherwise impossible
        if w[0] == '0':
            print(-1)
            continue

        res = n
        length = 1

        valid = True

        for i in range(1, n):
            inside_free = length - i
            outside_free = n - length

            if w[i-1] == '1':
                if outside_free <= 0:
                    valid = False
                    break
                res = res * outside_free % MOD
                length += 1
            else:
                if inside_free <= 0:
                    valid = False
                    break
                res = res * inside_free % MOD

        if not valid or res % c == 0:
            print(-1)
        else:
            print(res)

if __name__ == "__main__":
    solve()
