a, b = map(int, input().split())
if a % 2: exit(print(0))

n = (a + b) // 3
r = a // 2
if n < r: exit(print(0))

mod = 10 ** 9 + 7
fact = [1] * (n + 1)
for i in range(1, n + 1):
    fact[i] = fact[i - 1] * i % mod
print(fact[n] * pow(fact[r], -1, mod) * pow(fact[n - r], -1, mod) * pow(3, r, mod) % mod)
