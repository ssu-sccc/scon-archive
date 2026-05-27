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
    pts = [(data[i], data[i + 1]) for i in range(1, 2 * n + 1, 2)]
    pts.sort()

    x = [p[0] for p in pts]
    y = [p[1] for p in pts]

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

    S = 1000000000000000000
    E = 65535
    get0 = itemgetter(0)

    keys = []
    pos = []
    up = []
    down = []

    for j in range(n):
        xj = x[j]
        yj = y[j]
        lj = lo[j]

        a = newlist_hint(lj + 1)
        a.append((yj * S // xj, E))
        for i in range(lj):
            if y[i] < yj:
                a.append(((yj - y[i]) * S // (xj - x[i]), i))

        a.sort(key=get0)

        row = array('H', [E]) * j
        kk = newlist_hint(len(a))
        last = -1
        c = -1
        oi = 0

        for v, u in a:
            if v != last:
                kk.append(v)
                c += 1
                last = v
            if u == E:
                oi = c
            else:
                row[u] = c

        b = array('H', [0]) * len(kk)
        d = array('H', [0]) * len(kk)
        b[oi] = 1
        d[oi] = 1

        keys.append(kk)
        pos.append(row)
        up.append(b)
        down.append(d)

    ans = 1
    bl = bisect_left
    xx = x
    yy = y
    hh = hi
    pp = pos
    uu = up
    dd = down
    kk_all = keys

    for i in range(n):
        kk = kk_all[i]
        u = uu[i]
        d = dd[i]
        m = len(kk)

        z = 0
        for r in range(m):
            v = u[r]
            if v > z:
                z = v
            else:
                u[r] = z

        suf = [0] * m
        z = 0
        for r in range(m - 1, -1, -1):
            v = d[r]
            if v > z:
                z = v
            suf[r] = z

        xi = xx[i]
        yi = yy[i]

        for j in range(hh[i], n):
            dy = yy[j] - yi
            if dy <= 0:
                continue

            key = dy * S // (xx[j] - xi)
            r = bl(kk, key)
            idx = pp[j][i]

            if r:
                nv = u[r - 1] + 1
                dj = dd[j]
                if nv > dj[idx]:
                    dj[idx] = nv
                    if nv > ans:
                        ans = nv

            if r < m and kk[r] == key:
                r += 1

            if r < m:
                nv = suf[r] + 1
                uj = uu[j]
                if nv > uj[idx]:
                    uj[idx] = nv
                    if nv > ans:
                        ans = nv

    print(ans)

main()
