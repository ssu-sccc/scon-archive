z, S, a, b = '', "", 0, 0
for v in (input(), input())[1]:
	if 'S' == v:
		if "CJ" == S: a += 1
		if "JC" == S: b += 1
		z = ''; S = ""
	elif not z or z != v:
		S += v; z = v

print(a, b, sep='\n')
