import sys
from collections import deque

n = int(input())
g = [[] for _ in range(n + 1)]

for i in range(1, n + 1):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

color = [-1] * (n + 1)
color[1] = 0

q = deque([1])

while q:
    u = q.popleft()

    for v in g[u]:
        if color[v] == -1:
            color[v] = 1 ^ color[u]
            q.append(v)
        elif color[v] == color[u]:
            print(3)
            exit()

print(2)
