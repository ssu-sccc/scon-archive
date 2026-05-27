import os
from array import array

def main():
    data = list(map(int, os.read(0, 1 << 20).split()))
    if not data:
        return

    n = data[0]
    if n <= 1:
        os.write(1, (str(n) + '\n').encode())
        return

    pts = [(data[i], data[i + 1]) for i in range(1, (n << 1) + 1, 2)]
    pts.sort()

    xs = [0] * n
    ys = [0] * n
    for i, (x, y) in enumerate(pts):
        xs[i] = x
        ys[i] = y

    up = array('H', [0]) * (n * n)
    dn = array('H', [0]) * (n * n)

    m = n + 3

    bestUDx = [0] * m
    bestUDy = [0] * m
    usedU = [0] * m
    hasU = bytearray(m)

    bestDDx = [0] * m
    bestDDy = [0] * m
    usedD = [0] * m
    hasD = bytearray(m)

    candUDx = [0] * m
    candUDy = [0] * m
    candUVal = [0] * m

    candDDx = [0] * m
    candDDy = [0] * m
    candDVal = [0] * m

    xs_l = xs
    ys_l = ys
    up_l = up
    dn_l = dn

    bestUDx_l = bestUDx
    bestUDy_l = bestUDy
    usedU_l = usedU
    hasU_l = hasU

    bestDDx_l = bestDDx
    bestDDy_l = bestDDy
    usedD_l = usedD
    hasD_l = hasD

    candUDx_l = candUDx
    candUDy_l = candUDy
    candUVal_l = candUVal

    candDDx_l = candDDx
    candDDy_l = candDDy
    candDVal_l = candDVal

    ans = 1
    TH = 12

    for i in range(n):
        xi = xs_l[i]
        yi = ys_l[i]
        row = i * n

        uc = 1
        usedU_l[0] = 2
        hasU_l[2] = 1
        bestUDx_l[2] = xi
        bestUDy_l[2] = yi
        maxu = 2

        dc = 1
        usedD_l[0] = 2
        hasD_l[2] = 1
        bestDDx_l[2] = xi
        bestDDy_l[2] = yi
        maxd = 2

        for k in range(i):
            u = up_l[row + k]
            d = dn_l[row + k]
            if not u and not d:
                continue

            dx = xi - xs_l[k]
            dy = yi - ys_l[k]

            if d:
                v = d + 1
                if not hasU_l[v]:
                    hasU_l[v] = 1
                    usedU_l[uc] = v
                    uc += 1
                    bestUDx_l[v] = dx
                    bestUDy_l[v] = dy
                    if v > maxu:
                        maxu = v
                elif dy * bestUDx_l[v] < bestUDy_l[v] * dx:
                    bestUDx_l[v] = dx
                    bestUDy_l[v] = dy

            if u:
                v = u + 1
                if not hasD_l[v]:
                    hasD_l[v] = 1
                    usedD_l[dc] = v
                    dc += 1
                    bestDDx_l[v] = dx
                    bestDDy_l[v] = dy
                    if v > maxd:
                        maxd = v
                elif dy * bestDDx_l[v] > bestDDy_l[v] * dx:
                    bestDDx_l[v] = dx
                    bestDDy_l[v] = dy

        cu = 0
        curDx = 0
        curDy = 0
        first = 1
        for v in range(maxu, 1, -1):
            if not hasU_l[v]:
                continue
            dx = bestUDx_l[v]
            dy = bestUDy_l[v]
            if first or dy * curDx < curDy * dx:
                candUVal_l[cu] = v
                candUDx_l[cu] = dx
                candUDy_l[cu] = dy
                curDx = dx
                curDy = dy
                first = 0
                cu += 1

        for t in range(uc):
            hasU_l[usedU_l[t]] = 0

        cd = 0
        curDx = 0
        curDy = 0
        first = 1
        for v in range(maxd, 1, -1):
            if not hasD_l[v]:
                continue
            dx = bestDDx_l[v]
            dy = bestDDy_l[v]
            if first or dy * curDx > curDy * dx:
                candDVal_l[cd] = v
                candDDx_l[cd] = dx
                candDDy_l[cd] = dy
                curDx = dx
                curDy = dy
                first = 0
                cd += 1

        for t in range(dc):
            hasD_l[usedD_l[t]] = 0

        pos = (i + 1) * n + i

        if cu == 1:
            u0dx = candUDx_l[0]
            u0dy = candUDy_l[0]
            u0val = candUVal_l[0]
            umode = 1
        elif cu <= TH:
            umode = 2
        else:
            umode = 3
            uf0dx = candUDx_l[0]
            uf0dy = candUDy_l[0]
            uf0val = candUVal_l[0]
            ulast = cu - 1
            uldx = candUDx_l[ulast]
            uldy = candUDy_l[ulast]

        if cd == 1:
            d0dx = candDDx_l[0]
            d0dy = candDDy_l[0]
            d0val = candDVal_l[0]
            dmode = 1
        elif cd <= TH:
            dmode = 2
        else:
            dmode = 3
            df0dx = candDDx_l[0]
            df0dy = candDDy_l[0]
            df0val = candDVal_l[0]
            dlast = cd - 1
            dldx = candDDx_l[dlast]
            dldy = candDDy_l[dlast]

        for j in range(i + 1, n):
            yj = ys_l[j]
            if yj > yi:
                dx2 = xs_l[j] - xi
                if dx2:
                    dy2 = yj - yi

                    bestu = 0
                    bestd = 0

                    if umode == 1:
                        if u0dy * dx2 < dy2 * u0dx:
                            bestu = u0val
                    elif umode == 2:
                        for t in range(cu):
                            if candUDy_l[t] * dx2 < dy2 * candUDx_l[t]:
                                bestu = candUVal_l[t]
                                break
                    else:
                        if uf0dy * dx2 < dy2 * uf0dx:
                            bestu = uf0val
                        elif uldy * dx2 >= dy2 * uldx:
                            bestu = 0
                        else:
                            lo = 1
                            hi = cu
                            while lo < hi:
                                mid = (lo + hi) >> 1
                                if candUDy_l[mid] * dx2 < dy2 * candUDx_l[mid]:
                                    hi = mid
                                else:
                                    lo = mid + 1
                            bestu = candUVal_l[lo]

                    if dmode == 1:
                        if d0dy * dx2 > dy2 * d0dx:
                            bestd = d0val
                    elif dmode == 2:
                        for t in range(cd):
                            if candDDy_l[t] * dx2 > dy2 * candDDx_l[t]:
                                bestd = candDVal_l[t]
                                break
                    else:
                        if df0dy * dx2 > dy2 * df0dx:
                            bestd = df0val
                        elif dldy * dx2 <= dy2 * dldx:
                            bestd = 0
                        else:
                            lo = 1
                            hi = cd
                            while lo < hi:
                                mid = (lo + hi) >> 1
                                if candDDy_l[mid] * dx2 > dy2 * candDDx_l[mid]:
                                    hi = mid
                                else:
                                    lo = mid + 1
                            bestd = candDVal_l[lo]

                    if bestu:
                        up_l[pos] = bestu
                        if bestu > ans:
                            ans = bestu

                    if bestd:
                        dn_l[pos] = bestd
                        if bestd > ans:
                            ans = bestd

            pos += n

    os.write(1, (str(ans) + '\n').encode())

main()