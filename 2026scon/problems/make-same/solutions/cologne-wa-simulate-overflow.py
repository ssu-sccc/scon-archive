import sys

input = lambda: sys.stdin.readline().rstrip("\n")


def simulate_overflow(x):
    x %= 2 ** 32
    return x if x < 2 ** 31 else x - 2 ** 32


def ok(n, sum0, sum1):
    if sum0 % n != 0:
        return 'No'
    v = sum0 // n
    return 'Yes' if simulate_overflow(v * n * (n - 1) // 2 - sum1) == 0 else 'No'


def main():
    n = int(input())
    *a, = map(int, input().split())
    sum0, sum1 = sum(a), sum(i * v for i, v in enumerate(a))
    print(ok(n, sum0, sum1))

    q = int(input())
    for _ in range(q):
        i, x = map(int, input().split())
        i -= 1
        sum0 += x - a[i]
        sum1 += i * (x - a[i])

        a[i] = x

        print(ok(n, sum0, sum1))


if __name__ == '__main__':
    main()
