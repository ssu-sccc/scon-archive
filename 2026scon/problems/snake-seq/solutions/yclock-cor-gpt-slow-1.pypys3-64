import sys
from bisect import bisect_left

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    n = data[0]
    p = [(data[i], data[i + 1]) for i in range(1, 2 * n + 1, 2)]
    p.sort()

    x = [a for a, b in p]
    y = [b for a, b in p]
    sh = 60

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

    keys = []
    pos = []
    up = []
    down = []

    for j in range(n):
        xj = x[j]
        yj = y[j]
        a = [((yj << sh) // xj, -1)]
        for i in range(lo[j]):
            if y[i] < yj:
                a.append((((yj - y[i]) << sh) // (xj - x[i]), i))
        a.sort()

        row = [-1] * j
        kk = []
        last = None
        c = -1
        oi = 0

        for v, u in a:
            if v != last:
                kk.append(v)
                c += 1
                last = v
            if u < 0:
                oi = c
            else:
                row[u] = c

        b = [0] * len(kk)
        d = [0] * len(kk)
        b[oi] = d[oi] = 1

        keys.append(kk)
        pos.append(row)
        up.append(b)
        down.append(d)

    ans = 1
    bl = bisect_left

    for i in range(n):
        kk = keys[i]
        u = up[i]
        d = down[i]
        m = len(kk)

        pref = [0] * (m + 1)
        z = 0
        for r in range(m):
            v = u[r]
            if v > z:
                z = v
            pref[r + 1] = z

        suff = [0] * (m + 1)
        z = 0
        for r in range(m - 1, -1, -1):
            v = d[r]
            if v > z:
                z = v
            suff[r] = z

        xi = x[i]
        yi = y[i]

        for j in range(hi[i], n):
            dy = y[j] - yi
            if dy <= 0:
                continue

            key = (dy << sh) // (x[j] - xi)
            r = bl(kk, key)
            idx = pos[j][i]

            v = pref[r]
            if v:
                nv = v + 1
                dj = down[j]
                if nv > dj[idx]:
                    dj[idx] = nv
                    if nv > ans:
                        ans = nv

            if r < m and kk[r] == key:
                r += 1

            v = suff[r]
            if v:
                nv = v + 1
                uj = up[j]
                if nv > uj[idx]:
                    uj[idx] = nv
                    if nv > ans:
                        ans = nv

    print(ans)

main()
