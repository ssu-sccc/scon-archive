from math import factorial

a, b = map(int, input().split())
if a % 2: exit(print(0))

n = (a + b) // 3
r = a // 2
if n < r: exit(print(0))

mod = 10 ** 9 + 7
print(factorial(n) * pow(factorial(r), -1, mod) * pow(factorial(n - r), -1, mod) * pow(3, r, mod) % mod)
