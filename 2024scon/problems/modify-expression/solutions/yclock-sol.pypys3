N = int(input())
A = input().split()
X = input()

X = 'T' == X

for i in range(0, N, 2):
	A[i] = 'T' == A[i]

D = [[N] * 2 for _ in range(N)]

D[0][int(A[0])] = 0
D[0][int(not A[0])] = 1

for i in range(2, N, 2):
	for a in [True, False]:
		for b in [True, False]:
			for c in ['|', '&']:
				v = (a or b) if c == '|' else (a and b)
				r = int(b != A[i]) + int(('|' == A[i-1]) != ('|' == c)) + D[i-2][int(a)]
				D[i][int(v)] = min(D[i][int(v)], r)

print(D[-1][int(X)])
