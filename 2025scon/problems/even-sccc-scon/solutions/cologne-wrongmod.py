n = int(input())
MOD = 10 ** 9 + 7

ans = (pow(26, n, MOD) + pow(22, n, MOD)) // 2
print(ans)