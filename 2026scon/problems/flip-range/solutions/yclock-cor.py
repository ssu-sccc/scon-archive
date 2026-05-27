a, b = 0, ''
for v in (input(), input())[1]:
	a += b == v; b = v

print((a + 1) // 2)
