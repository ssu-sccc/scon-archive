N, K = map(int, input().split())
A = list(map(int, input().split()))

X = 0
Ans = 0

for v in A[0:N-1]:
	X = max(0, X + v)
	if K <= X:
		Ans += 1

print(Ans)
