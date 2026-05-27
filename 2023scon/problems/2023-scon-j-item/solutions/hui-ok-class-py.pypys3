class trie:
    def __init__(self):
        self.c = [None, None]
        self.sz = 0

    def insert(self, v, d):
        self.sz += 1
        if d == 60: return
        if not self.c[v%2]: self.c[v%2] = trie()
        self.c[v%2].insert(v//2, d+1)

def dfs(node, take):
    if not node or node.sz == take: return 0
    if not node.c[0] and not node.c[1]: return node.sz - take
    l, r = node.c
    if not l: return dfs(r, take+1) + 1
    if not r: return dfs(l, take+1) + 1
    return max(dfs(l, max(0,take-r.sz)+1), dfs(r, max(0,take-l.sz)+1)) + 1

n = int(input())
a = list(map(int, input().split()))

t = trie()
for i in a: t.insert(i, 0)
print(dfs(t, 0))