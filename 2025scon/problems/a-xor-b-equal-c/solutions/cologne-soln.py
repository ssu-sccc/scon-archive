x, y = map(int, input().split())

n = (x+y)//3
r = x//2


def f(n):
    a = 1
    for i in range(1, n+1):
        a *= i
    return a


if x % 2 == 1 or n < r:
    print(0)
else:
    print(pow(3, r) * f(n)//(f(r)*f(n-r)) % (10**9+7))
