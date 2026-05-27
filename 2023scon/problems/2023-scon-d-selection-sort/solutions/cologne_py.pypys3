import sys


class Tree:

    def __init__(self, A):
        N = 1
        while N < len(A):
            N *= 2
        self.N = N
        self.idx = [float('inf')]*N + A + [float('inf')] * (N-len(A))
        for i in range(N-1, 0, -1):
            self.idx[i] = min(self.idx[2*i], self.idx[2*i+1])

    def __setitem__(self, i, v):
        i += self.N
        self.idx[i] = v
        while i > 1:
            i //= 2
            self.idx[i] = min(self.idx[2*i], self.idx[2*i+1])

    def __getitem__(self, i):
        return self.idx[i+self.N]

    def min_idx(self):
        i = 1
        while i < self.N:
            if self.idx[2*i] < self.idx[2*i+1]:
                i = 2*i
            else:
                i = 2*i+1
        return i-self.N


def main():
    input = sys.stdin.readline
    N = int(input())
    A = [int(x)-1 for x in input().split()]
    T = Tree(A)
    ans = [0] * N
    for i in range(N):
        j = T.min_idx()
        ans[T[i]] += j-i
        ans[T[j]] += j-i
        T[j] = T[i]
        T[i] = float('inf')
    print(*ans)


if __name__ == '__main__':
    main()
