import sys
sys.setrecursionlimit(10**6)

def dfs(v=1, c=1):
    if C[v]:
        return C[v] == c
    C[v] = c
    for i in G[v]:
        if not dfs(i, -c):
            return False
    return True

N = int(input().strip())
G = [[] for _ in range(N + 1)]
C = [0] * (N + 1)

for _ in range(N):
    s, e = map(int, input().split())
    G[s].append(e)
    G[e].append(s)

print(2 if dfs() else 3)