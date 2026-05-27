import sys
input = sys.stdin.readline

MOD = 1000000007

N, M = map(int, input().split())
m = M >> 1

half = [0] * (N + 1)
dp = [[0] * (1 << m) for _ in range(N + 1)]

for i in range(1, N + 1):
    S = input().strip()
    for j in range(m):
        half[i] <<= 1
        if S[j] != S[M - 1 - j]:
            half[i] |= 1

for i in range(1, N + 1):
    for j in range(1 << m):
        dp[i][j] = dp[i - 1][j]

    dp[i][half[i]] = (dp[i][half[i]] + 1) % MOD

    for j in range(1 << m):
        dp[i][j ^ half[i]] = (dp[i][j ^ half[i]] + dp[i - 1][j]) % MOD

print(dp[N][0])