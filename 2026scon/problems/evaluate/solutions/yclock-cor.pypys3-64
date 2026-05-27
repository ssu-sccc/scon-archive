from heapq import heappush, heappop

n, k = map(int, input().split())
A = list(map(int, input().split()))

s, e = 1, max(A) + k
while s < e:
	m = (s + e + 1) // 2
	V, r, h = [], k, 0
	for a in A:
		if a < m:
			heappush(V, m - a)
			if h: h -= 1
			else: r -= heappop(V); h += 1
		else: h += 1
	if r < 0: e = m - 1
	else: s = m

print(s)
