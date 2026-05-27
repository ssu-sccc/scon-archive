

import math


def main():

    f = [1] * 5001
    for i in range(1, 5001):
        f[i] = f[i-1] * i

    t = int(input())
    for _ in range(t):
        n1,r1,n2,r2 = map(int, input().split())
        c1 = f[n1] // (f[r1] * f[n1-r1])
        c2 = f[n2] // (f[r2] * f[n2-r2])
        print(1 if math.gcd(c1, c2) == 1 else 0)


if __name__ == "__main__":
    main()
