import sys
input = lambda: sys.stdin.readline().rstrip()

trie = [[0, 0] for _ in range(10010010)]
c = [0] * 10010010
cnt = 0

n = int(input())
a = [*map(int, input().split())]

def dfs(u, left) :
    if u == 0 : return 0
    if c[u] < left : return -n

    L, R = trie[u]
    if L == 0 and R == 0 : return c[u]-left
    if c[u] == left : return 0

    if L == 0 : return dfs(R, left+1)+1
    if R == 0 : return dfs(L, left+1)+1

    return max(dfs(L, max(0, left+1-c[R])), dfs(R, max(0, left+1-c[L])))+1

for i in range(n) :
    u = 0
    for j in range(60) :
        x = (a[i] >> j) & 1
        if not trie[u][x] :
            cnt += 1
            trie[u][x] = cnt
        u = trie[u][x]
        c[u] += 1

print(max(dfs(trie[0][0], 0), dfs(trie[0][1], 0)))