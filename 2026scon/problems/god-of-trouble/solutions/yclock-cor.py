n, k = int(input()), 0

def ask(x: int) -> int:
	global k
	k = (k + 1) % 10; print(f"? {x + 1}")
	return int(input())

A = [[] for _ in range(4)]
for i in range(n // 2):
	A[ask(i) << 1 | ask(n - i - 1)].append(i)
	if not k:
		a, v = (A[0][0], 0) if A[0] else ((A[3][0], 1) if A[3] else (0, -1))
		if v != ask(a) and -1 < v: A = A[::-1]
		a, v = (A[1][0], 0) if A[1] else ((A[2][0], 1) if A[2] else (0, -1))
		if v != ask(a) and -1 < v: A = [A[0], A[2], A[1], A[3]]

B = [ask(n // 2)] * n
for k, V in enumerate(A):
	for v in V:
		B[v] = k >> 1; B[n - v - 1] = k & 1

print('!', *B)
