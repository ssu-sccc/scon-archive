import sys
import heapq

input = lambda: sys.stdin.readline().rstrip("\n")


def main():
    n, b = map(int, input().split())
    *a, = map(int, input().split())

    def ok(ls, cut):
        h = []
        cur = 0
        for v in ls:
            if v >= 0:
                cur += 1
            else:
                heapq.heappush(h, -v)
                cur -= 1

            if cur == -1:
                cur = 1
                cut -= heapq.heappop(h)

        return cut >= 0

    lo = 1
    hi = 2 * 10 ** 9 + 1
    while lo + 1 != hi:
        mi = (lo + hi) // 2
        if ok((i - mi for i in a), b):
            lo = mi
        else:
            hi = mi

    print(lo)


if __name__ == '__main__':
    main()
