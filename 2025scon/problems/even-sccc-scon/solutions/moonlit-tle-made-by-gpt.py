MOD = 10**9 + 7

def modinv(x):
    return pow(x, MOD - 2, MOD)

def precompute_factorials(n):
    fact = [1] * (n + 1)
    inv_fact = [1] * (n + 1)

    for i in range(1, n + 1):
        fact[i] = (fact[i - 1] * i) % MOD

    inv_fact[n] = modinv(fact[n])
    for i in range(n - 1, -1, -1):
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD

    return fact, inv_fact

def combination(n, r, fact, inv_fact):
    if r < 0 or r > n:
        return 0
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD

def solve(n):
    fact, inv_fact = precompute_factorials(n)

    even_r_values = [r for r in range(0, n + 1, 2)]  # r = 0, 2, ..., n

    nCr = [combination(n, r, fact, inv_fact) for r in even_r_values]
    pow24 = [pow(24, n-r, MOD) for r in even_r_values]
    pow2 = [pow(2, r, MOD) for r in even_r_values]

    total = 0
    for a, b, c in zip(nCr, pow24, pow2):
        total = (total + a * b % MOD * c % MOD) % MOD

    return total

# 예시 사용:
n = int(input())
print(solve(n))

"""
nC0*24**(n-0)*2**0 +
nC2*24**(n-2)*2**2 +
nC4*24**(n-4)*2**4 +
...을 빠르게 해결한다.
"""