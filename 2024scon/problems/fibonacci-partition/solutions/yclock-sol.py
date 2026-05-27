def f(V):
	print(len(V))
	print(*V)


N = int(input())

V = list(range(1, N+1))

A = []
B = []

while 2 < len(V):
	B.append(V[-1])
	A.extend(V[-3:-1])
	V = V[:-3]

if 1 < len(V):
	A.append(1)
	B.append(2)

f(A)
f(B)
