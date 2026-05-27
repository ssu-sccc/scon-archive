

import math


def naive_is_coprime(n1, r1, n2, r2, f):
    c1 = f[n1] // (f[r1] * f[n1-r1])
    c2 = f[n2] // (f[r2] * f[n2-r2])

    for i in range(2, 5001):
        if c1 % i == 0 and c2 % i == 0:
            return 0

    return 1


def main():

    f = [1] * 5001
    for i in range(1, 5001):
        f[i] = f[i-1] * i

    ans = {}

    t = int(input())
    for _ in range(t):
        n1, r1, n2, r2 = map(int, input().split())

        if ans.get((n1, r1, n2, r2)):
            print(ans[(n1, r1, n2, r2)])
            continue

        ans[(n1, r1, n2, r2)] = naive_is_coprime(n1, r1, n2, r2, f)
        print(ans[(n1, r1, n2, r2)])


if __name__ == "__main__":
    main()
