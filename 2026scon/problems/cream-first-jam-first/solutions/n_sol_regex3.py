import re

N = int(input())
s = input().strip()

parts = re.findall(r'[CJ]*S', s)

cream = sum(1 for x in parts if re.fullmatch(r'C+J+S', x))
jam = sum(1 for x in parts if re.fullmatch(r'J+C+S', x))

print(cream)
print(jam)