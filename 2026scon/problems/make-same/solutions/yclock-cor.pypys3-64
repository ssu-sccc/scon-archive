n = int(input())
A = list(map(int, input().split()))
s0, s1 = sum(A), sum(i * v for i, v in enumerate(A))
for t in range(int(input()) + 1):
	if t:
		i, v = map(int, input().split())
		i -= 1
		d = v - A[i]; s0 += d; s1 += i * d
		A[i] = v
	w = s0 // n
	print("YES" if w * n == s0 and (n - 1) * n // 2 * w == s1 else "NO")
