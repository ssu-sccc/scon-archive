import sys
import heapq

def solve():
    input = sys.stdin.buffer.readline

    n, m = map(int, input().split())
    A = list(map(int, input().split()))

    def judge(x: int) -> bool:
        c = 0
        cost = 0
        pq = []  # store patch costs: x - A[i]

        for v in A:
            if v >= x:
                c += 1
            else:
                heapq.heappush(pq, x - v)
                c -= 1
                if c < 0:
                    if pq:
                        cost += heapq.heappop(pq)
                    else:
                        return False
                    c += 2

        return cost <= m

    l, r = 0, 2_000_000_001
    while l + 1 < r:
        mid = (l + r) >> 1
        if judge(mid):
            l = mid
        else:
            r = mid

    sys.stdout.write(str(l) + '\n')

if __name__ == "__main__":
    solve()