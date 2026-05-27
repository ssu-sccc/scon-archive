import heapq
 
N, M, C, D = map(int, input().split())
k = list(map(int, input().split()))
 
arr = [[0] * (M + 1) for _ in range(N + 1)]
dp = [[0] * (M + 1) for _ in range(N + 1)]

for i in range(1, N + 1):
    for j in range(1, M + 1):
        arr[i][j] = M - abs(j - k[i - 1])
 
for j in range(1, M + 1):
    dp[1][j] = arr[1][j]
 
pqL = [[] for _ in range(C)]
pqR = [[] for _ in range(C)]
 
for i in range(2, N + 1):
    for j in range(C):
        pqL[j].clear()
        pqR[j].clear()
 
    for j in range(1, M + 1):
        idx = j % C
        heapq.heappush(pqL[idx], (-dp[i - 1][j], j))
        while pqL[idx] and abs(j - pqL[idx][0][1]) > D:
            heapq.heappop(pqL[idx])
        if pqL[idx]:
            dp[i][j] = max(dp[i][j], -pqL[idx][0][0] + arr[i][j])
 
    for j in range(M, 0, -1):
        idx = j % C
        heapq.heappush(pqR[idx], (-dp[i - 1][j], j))
        while pqR[idx] and abs(j - pqR[idx][0][1]) > D:
            heapq.heappop(pqR[idx])
        if pqR[idx]:
            dp[i][j] = max(dp[i][j], -pqR[idx][0][0] + arr[i][j])
 
print(max(dp[N][1:]))
