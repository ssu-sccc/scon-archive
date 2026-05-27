N = int(input())

for _ in range(N):
	S = input()

	if (
		len([v for v in S if v.isupper()]) <= (len(S) - len([v for v in S if v.isupper()]))
		and len(S) <= 10
		and [v for v in S if not v.isdigit()]
	):
		print(S)
