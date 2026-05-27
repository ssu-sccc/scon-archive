import sys

n, m = map(int, input().split())
g = [[False for _ in range(n)] for _ in range(n)]

res = 0

for i in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u][v] = g[v][u] = True

def is_finish():
    for i in range(n):
        for j in range(n):
            if i != j and not g[i][j]:
                return False
    return True

while not is_finish():
    a, b, c = -1, -1, -1
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if i == j or j == k or k == i: continue
                x = 0 if g[i][j] else 1
                y = 0 if g[j][k] else 1
                z = 0 if g[k][i] else 1
                if x + y + z == 1: a, b, c = i, j, k

    if a != -1:
        g[a][b] = g[a][c] = True
        g[b][a] = g[b][c] = True
        g[c][a] = g[c][b] = True
        continue

    for i in range(n):
        for j in range(n):
            for k in range(n):
                if i == j or j == k or k == i: continue
                x = 0 if g[i][j] else 1
                y = 0 if g[j][k] else 1
                z = 0 if g[k][i] else 1
                if x + y + z == 2: a, b, c = i, j, k

    if a != -1:
        g[a][b] = g[a][c] = True
        g[b][a] = g[b][c] = True
        g[c][a] = g[c][b] = True
        res += 1
        continue

    print('f')
    sys.exit(1)

print(res)