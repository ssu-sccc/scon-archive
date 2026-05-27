import sys
from collections import Counter

input = lambda: sys.stdin.readline().rstrip("\n")


def main():
    input()
    s = input()
    input()
    t = input()
    c = Counter(s + t)
    if c.get('I', 0) >= 1 and c.get('C', 0) >= 1 and c.get('P', 0) >= 1:
        print('m4us happy')
    else:
        print('m4us sad')


if __name__ == '__main__':
    main()
