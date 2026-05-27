def solve(n, s, e):
	if s > e:
		s, e = n-s+1, n-e+1

	print(min([
		(s-1 + n-1 + n-e, 0, 'zero'),
		(s-1 + 1 + n-s-1 + e-s-1, 1, 'one-left-jump'),
		(s-1 + e-2 + 1 + n-e, 1, 'one-left-right-jump'),
		(1 + e-s-1 + e-2 + 1 + n-e, 1, 'one-right-left-jump'),
		(n-s + 1 + e-1, 1, 'one-rightall-jump'),
		(1 + n-1 + n-e, 1, 'one-jumpleft'),
		(1 + n-1 + e-1, 1, 'one-jump-right'),
		(n-1, 2, 'two'),
	])[1])


for _ in range(int(input())):
	solve(*list(map(int, input().split())))
