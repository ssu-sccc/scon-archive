N = int(input())

for _ in range(N):
	S = input()

	if (
		(len(S) - len([v for v in S if v.islower()])) <= len([v for v in S if v.islower()])
		and len(S) <= 10
		and [v for v in S if not v.isdigit()]
	):
		print(S)
