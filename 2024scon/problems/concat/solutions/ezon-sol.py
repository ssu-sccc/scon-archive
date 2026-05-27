import sys

arr_len = int(sys.stdin.readline())

strA = ""
arrA = list(sys.stdin.readline().strip().split())
for string in arrA:
    strA += string
strA = int(strA)

strB = ""
arrB = list(sys.stdin.readline().strip().split())
for string in arrB:
    strB += string
strB = int(strB)

if strA <= strB:
    print(strA)
else:
    print(strB)