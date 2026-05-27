a, b, m, V = '', 0, '', []
for v in (input(), input())[1][::-1] + '.':
	if a == v: b += 1; continue
	if b: V.append((b if b and a < m else 1, a))
	m = a; a = v; b = 1

print(''.join(a * b for (a, b) in V[::-1]))
