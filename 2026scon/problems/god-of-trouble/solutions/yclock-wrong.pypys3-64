n, k = int(input()), 0

def ask(x: int) -> int:
	global k
	k = (k + 1) % 10; print(f"? {x + 1}")
	return int(input())

A = [[] for _ in range(4)]
for i in range(n // 2 + 1):
	if not k:
		a, v = (A[0][0], 0) if A[0] else ((A[3][0], 1) if A[3] else (-1, -1))
		if -1 < v and v != ask(a): A = A[::-1]
		a, v = (A[1][0], 0) if A[1] else ((A[2][0], 1) if A[2] else (-1, -1))
		if -1 < v and v != ask(a): A[1], A[2] = A[2], A[1]

	if i < n // 2: A[ask(i) << 1 | ask(n - i - 1)].append(i)

B = [ask(n // 2)] * n
for k, V in enumerate(A):
	for v in V:
		B[v] = k >> 1; B[n - v - 1] = k & 1

print("! " + ' '.join(map(str, B)))
