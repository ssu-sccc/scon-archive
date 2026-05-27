import sys
from bisect import bisect_left
from array import array
from operator import itemgetter

try:
    from __pypy__ import newlist_hint
except ImportError:
    def newlist_hint(n):
        return []

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    n = data[0]
    p = [(data[i], data[i + 1]) for i in range(1, 2 * n + 1, 2)]
    p.sort()

    x = [a for a, b in p]
    y = [b for a, b in p]

    lo = [0] * n
    hi = [0] * n
    i = 0
    while i < n:
        j = i + 1
        while j < n and x[j] == x[i]:
            j += 1
        for k in range(i, j):
            lo[k] = i
            hi[k] = j
        i = j

    base = [0] * n
    s = 0
    for i in range(n):
        base[i] = s
        s += i

    pos = array('H', [0]) * s
    keys = []
    up = []
    down = []

    sh = 60
    inf = 65535
    get0 = itemgetter(0)

    for j in range(n):
        xj = x[j]
        yj = y[j]
        a = newlist_hint(lo[j] + 1)
        a.append(((yj << sh) // xj, inf))

        for i in range(lo[j]):
            if y[i] < yj:
                a.append((((yj - y[i]) << sh) // (xj - x[i]), i))

        a.sort(key=get0)

        bj = base[j]
        kk = newlist_hint(len(a))
        last = -1
        c = -1
        oi = 0

        for v, u in a:
            if v != last:
                kk.append(v)
                c += 1
                last = v
            if u == inf:
                oi = c
            else:
                pos[bj + u] = c

        m = len(kk)
        u = array('H', [0]) * m
        d = array('H', [0]) * m
        u[oi] = 1
        d[oi] = 1

        keys.append(kk)
        up.append(u)
        down.append(d)

    ans = 1
    bl = bisect_left
    yy = y
    hh = hi
    bs = base
    ps = pos
    ks = keys
    uu = up
    dd = down

    for i in range(n):
        k = ks[i]
        u = uu[i]
        d = dd[i]
        m = len(k)

        z = 0
        for r in range(m):
            v = u[r]
            if v > z:
                z = v
            else:
                u[r] = z

        cur = z
        z = 0
        for r in range(m - 1, -1, -1):
            v = d[r]
            if v > z:
                z = v
            else:
                d[r] = z

        if z > cur:
            cur = z
        if cur + n - i - 1 <= ans:
            continue

        yi = yy[i]

        for j in range(hh[i], n):
            if yy[j] <= yi:
                continue

            idx = ps[bs[j] + i]
            key = ks[j][idx]
            r = bl(k, key)

            if r:
                nv = u[r - 1] + 1
                dj = dd[j]
                if nv > dj[idx]:
                    dj[idx] = nv
                    if nv > ans:
                        ans = nv

            if r < m and k[r] == key:
                r += 1

            if r < m:
                nv = d[r] + 1
                uj = uu[j]
                if nv > uj[idx]:
                    uj[idx] = nv
                    if nv > ans:
                        ans = nv

    print(ans)

main()
