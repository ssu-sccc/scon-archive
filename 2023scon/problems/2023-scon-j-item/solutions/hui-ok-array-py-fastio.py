import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

c = [[0 for _ in range(2)] for _ in range(n*61+2)]
s = [0] * (n*61+2)
p = 1

def insert(v):
    global p
    x = 1
    s[x] += 1
    for i in range(60):
        key = v >> i & 1
        if c[x][key] == 0:
            p += 1
            c[x][key] = p
        x = c[x][key]
        s[x] += 1

def dfs(node, take):
    if node == 0 or s[node] == take: return 0
    if c[node][0] == 0 and c[node][1] == 0: return s[node] - take
    l, r = c[node]
    if l == 0: return dfs(r, take+1) + 1
    if r == 0: return dfs(l, take+1) + 1
    return max(dfs(l, max(0,take-s[r])+1), dfs(r, max(0,take-s[l])+1)) + 1

for i in a: insert(i)
print(dfs(1, 0))
