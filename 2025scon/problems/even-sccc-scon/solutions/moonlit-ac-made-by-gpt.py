ints=lambda: list(map(int, input().split()))
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
    even_r_values = [r for r in range(0, n + 1, 2)]  # r = 0, 2, ..., n (짝수만)
    k = len(even_r_values)

    # nCr 계산
    nCr = [combination(n, r, fact, inv_fact) for r in even_r_values]

    # pow24 계산 (뒤에서부터, 점화식 이용)
    pow24 = [0] * k
    pow24[-1] = 1 if n%2==0 else 24  # 초기값
    for i in range(k - 2, -1, -1):
        pow24[i] = pow24[i + 1] * 24**2 % MOD

    # pow2 계산 (앞에서부터, 점화식 이용)
    pow2 = [0] * k
    pow2[0] = 1  # 2^0
    for i in range(1, k):
        pow2[i] = pow2[i - 1] * 4 % MOD

    # 총합 계산
    total = 0
    for a, b, c in zip(nCr, pow24, pow2):
        total = (total + a * b % MOD * c % MOD) % MOD

    return total

# 예시 사용:
n = int(input())
print(solve(n))

#pow24, pow2를 더 효율적으로 계산