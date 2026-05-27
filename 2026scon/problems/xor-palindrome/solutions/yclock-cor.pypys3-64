MOD = 1_000_000_007
n, k = map(int, input().split())
A = [int(input(), 2) for _ in range(n)]
B = [0] * k

for z in range(k):
	u = 0
	for i, v in enumerate(A):
		if v >> z & 1:
			u = v
			break

	if not u:
		continue

	B[z] = u
	for i, v in enumerate(A):
		if v >> z & 1:
			A[i] ^= u

zc = n - len([v for v in B if v])

Ans = 0
for w in range(1 << k):
	s = f"{w:0{k}b}"
	if s != s[::-1]:
		continue

	for i, v in enumerate(B):
		if v and (w >> i & 1):
			w ^= v

	if not w:
		Ans += 1

for _ in range(zc):
	Ans <<= 1
	if MOD <= Ans:
		Ans -= MOD

print((Ans + MOD - 1) % MOD)
