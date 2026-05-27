n, m, q = map(int, input().split())
G = [[] for _ in range(n)]
for _ in range(m):
	a, b = map(lambda s: int(s) - 1, input().split())
	G[a].append(b)
	G[b].append(a)

W = [dict() for _ in range(n)]
for i, (w, V) in enumerate(zip(W, G)):
	for v in V:
		d = len(G[v])
		w[d] = w.get(d, 0) + 1

A = [0] * n
Ans = []
for _ in range(q):
	V = list(map(int, input().split()))
	if 1 == V[0]:
		w = V[2]
		for v, k in W[V[1] - 1].items():
			A[v] += k * w
	else:
		Ans.append(A[V[1]])

print('\n'.join(map(str, Ans)))
