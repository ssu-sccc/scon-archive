import sys
from itertools import groupby, pairwise

input = lambda: sys.stdin.readline().rstrip("\n")


def main():
    input()
    s = [list(y) for x, y in groupby(input())]
    for a, b in pairwise(s):
        if a[0] > b[0]:
            del a[1:]
    del s[-1][1:]
    print(''.join(''.join(x) for x in s))


if __name__ == '__main__':
    main()
