import sys
sys.setrecursionlimit(10**6)
input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
graph=[[] for i in range(n+1)]
for i in range(n):
    x, y=ints()
    graph[x].append(y)
    graph[y].append(x)

color=[-1]*(n+1)
def dfs(node, c): #1이면 겹침
    if color[node] != -1:
        return 0
    ans=0
    color[node]=c
    for nxt in graph[node]:
        if color[nxt]== -1:
            ans |= dfs(nxt, (c+1)%2)
        elif color[nxt]==c:
            return 1
    return ans
k=dfs(1, 0)
print(k+2)
