import sys
input = sys.stdin.readline

N = int(input())
ans = [0] * (N + 1)

for i in range(1, N, 2):
    ans[i] = (i + 1) >> 1
    ans[i + 1] = -ans[i]

print(*ans[:N])