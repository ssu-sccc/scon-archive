N = int(input())
A = input().split()
X = input()

X = 'T' == X

for i in range(0, N, 2):
	A[i] = 'T' == A[i]

for i in range(1, N, 2):
	A[i+1] = (A[i-1] and A[i+1]) if '&' == A[i] else (A[i-1] or A[i+1])

if A[-1] == X:
	print(0)
elif A[-1] and A[-3] and '|' == A[-2]:
	print(2)
elif not A[-1] and not A[-3] and '&' == A[-2]:
	print(2)
else:
	print(1)
