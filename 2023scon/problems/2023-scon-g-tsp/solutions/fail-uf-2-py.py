n, m, s = map(int, input().split())
p = [0] * n
e = []
res = 0

def find(v):
    if v == p[v]: return v
    else:
        p[v] = find(p[v])
        return p[v]

def merge(u, v):
    u = find(u)
    v = find(v)
    if u == v: return False
    p[v] = u
    return True

for i in range(m):
    u, v, w = map(int, input().split())
    e.append((w, u-1, v-1))

for i in range(n): p[i] = i
e.sort()

for w, u, v in e:
    if merge(u, v): res += w

print(res)