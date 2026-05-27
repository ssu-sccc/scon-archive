def read_time(x):
	h, m = map(int, x.split(':'))
	return h * 60 + m


A = []
N = 0

for a in range(int(input())):
	n = int(input())
	N += n

	for _ in range(n):
		b, c, d, e = input().split()
		b = int(b)
		c = int(c) * 24 * 60
		d = c + read_time(d)
		e = c + read_time(e)

		A.append((a, b, d, e))


Ans = 0

for key in range(1, 1 << N):
	V = [A[i] for i in range(N) if key >> i & 1]

	if any([V[i-1][0] == V[i][0] for i in range(1, len(V))]):
		continue

	if 22 != sum([v[1] for v in V]):
		continue

	W = []

	for v in V:
		W.append((v[2], -1))
		W.append((v[3] - 1, 1))

	W.sort()

	if any([W[i][1] != (1 if i % 2 else -1) for i in range(len(W))]):
		continue

	Ans += 1


print(Ans)
