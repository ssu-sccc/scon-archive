N = int(input())
A = input().split()
X = input()

X = 'T' == X

for i in range(0, N, 2):
	A[i] = 'T' == A[i]

r = A[0]

for i in range(1, N, 2):
	r = (r and A[i+1]) if '&' == A[i] else (r or A[i+1])


print(0 if r == X else 1)
