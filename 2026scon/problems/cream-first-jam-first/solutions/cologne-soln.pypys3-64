import sys

input = lambda: sys.stdin.readline().rstrip("\n")


def main():
    input()
    t = input().split('S')
    v1 = v2 = 0
    for s in t:
        cj, jc = s.count('CJ'), s.count('JC')
        v1 += (cj == 1) and (jc == 0)
        v2 += (cj == 0) and (jc == 1)

    print(v1)
    print(v2)


if __name__ == '__main__':
    main()
