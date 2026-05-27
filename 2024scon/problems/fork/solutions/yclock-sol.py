N, K = map(int, input().split())
A = list(map(int, input().split()))

S = [0]
for i in range(N):
	S.append(S[-1] + A[i])

D = [max(0, s) for s in S]
for i in range(1, N+1):
	D[i] = max(D[i], D[i-1])

X = -S[0] + D[0]
for i in range(K, N+1):
	D[i] = max(D[i], D[i-1], S[i] + X)
	X = max(X, -S[i-K+1] + D[i-K+1])

Ans = 0

X = 0
for i in range(N, 0, -1):
	X = max(X, S[N] - S[i-1])
	Ans = max(Ans, D[i-1] + X)

print(Ans)
