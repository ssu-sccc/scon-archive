import sys
from functools import cmp_to_key

def solve():
    input = sys.stdin.buffer.readline

    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    

    I = list(range(1, n + 1))

    def cmp(a, b):
        lhs = B[a-1] * A[b-1]
        rhs = B[b-1] * A[a-1]
        if lhs == rhs:
            return -1 if a < b else (1 if a > b else 0)
        return -1 if lhs < rhs else 1

    I.sort(key=cmp_to_key(cmp))
    sys.stdout.write(str(I[n-1]) + '\n')

if __name__ == "__main__":
    solve()