import re
import sys

input = sys.stdin.readline

N = int(input())
s = input().strip()

cream_pattern = re.compile(r'^C+J+$')
jam_pattern = re.compile(r'^J+C+$')

cream_first = 0
jam_first = 0

parts = s.split('S')
# 마지막은 항상 빈 문자열
for cur in parts[:-1]:
    if cream_pattern.fullmatch(cur):
        cream_first += 1
    elif jam_pattern.fullmatch(cur):
        jam_first += 1

print(cream_first)
print(jam_first)