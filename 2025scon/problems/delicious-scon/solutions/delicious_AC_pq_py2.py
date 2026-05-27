import sys
import heapq

input = sys.stdin.readline

N, M, C, D = map(int, input().split())
arr = [[0] * (M + 1) for _ in range(N + 1)]
dp = [[0] * (M + 1) for _ in range(N + 1)]

b = list(map(int, input().split()))
for i in range(1, N + 1):
    k = b[i - 1]
    for j in range(1, M + 1):
        arr[i][j] = M - abs(j - k)

for j in range(1, M + 1):
    dp[1][j] = arr[1][j]

pq = [[] for _ in range(C + 1)]

for i in range(2, N + 1):
    for j in range(1, C + 1):
        idx = j
        while idx - D <= M:
            if idx <= M:
                heapq.heappush(pq[j], (-dp[i - 1][idx], idx))
            if idx - D >= 1:
                while pq[j] and pq[j][0][1] < idx - D - D:
                    heapq.heappop(pq[j])
                if pq[j]:
                    max_val = -pq[j][0][0]
                    dp[i][idx - D] = max(dp[i][idx - D], max_val + arr[i][idx - D])
            idx += C
        pq[j].clear()

print(max(dp[N][1:]))
