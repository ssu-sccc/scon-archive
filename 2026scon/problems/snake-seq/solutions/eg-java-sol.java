import java.io.*;

public class Main {
    static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        long nextLong() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= 32 && c != -1);

            long sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            long val = 0;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }

    static int n, w, ans;
    static long[] x, y;
    static short[] loLen, loPrev, hiLen, hiPrev;
    static int[] loSz, hiSz, base;

    static int cmpXY(long ax, long ay, long bx, long by) {
        if (ax != bx) return ax < bx ? -1 : 1;
        if (ay != by) return ay < by ? -1 : 1;
        return 0;
    }

    static void swapPoint(int i, int j) {
        long tx = x[i];
        x[i] = x[j];
        x[j] = tx;
        long ty = y[i];
        y[i] = y[j];
        y[j] = ty;
    }

    static void insertionSortPoints(int l, int r) {
        for (int i = l + 1; i <= r; i++) {
            long vx = x[i], vy = y[i];
            int j = i - 1;
            while (j >= l && cmpXY(vx, vy, x[j], y[j]) < 0) {
                x[j + 1] = x[j];
                y[j + 1] = y[j];
                j--;
            }
            x[j + 1] = vx;
            y[j + 1] = vy;
        }
    }

    static void sortPoints(int l, int r) {
        while (l < r) {
            if (r - l <= 16) {
                insertionSortPoints(l, r);
                return;
            }

            int m = (l + r) >>> 1;
            long px = x[m], py = y[m];
            int lt = l, i = l, gt = r;

            while (i <= gt) {
                int c = cmpXY(x[i], y[i], px, py);
                if (c < 0) {
                    swapPoint(lt++, i++);
                } else if (c > 0) {
                    swapPoint(i, gt--);
                } else {
                    i++;
                }
            }

            if (lt - l < r - gt) {
                sortPoints(l, lt - 1);
                l = gt + 1;
            } else {
                sortPoints(gt + 1, r);
                r = lt - 1;
            }
        }
    }

    static int cmp128(long a, long b, long c, long d) {
        long hi1 = Math.multiplyHigh(a, b);
        long hi2 = Math.multiplyHigh(c, d);
        if (hi1 != hi2) return hi1 < hi2 ? -1 : 1;
        long lo1 = a * b;
        long lo2 = c * d;
        return Long.compareUnsigned(lo1, lo2);
    }

    static int cmpPrevPrev(int a, int b, long xv, long yv) {
        return cmp128(yv - y[a], xv - x[b], yv - y[b], xv - x[a]);
    }

    static int cmpPrevEdge(int a, long xv, long yv, long xt, long yt) {
        return cmp128(yv - y[a], xt - xv, yt - yv, xv - x[a]);
    }

    static int lowerBound(short[] arr, int b, int s, int target) {
        if (s <= 16) {
            int pos = 0;
            while (pos < s && arr[b + pos] < target) pos++;
            return pos;
        }
        int l = 0, r = s;
        while (l < r) {
            int m = (l + r) >>> 1;
            if (arr[b + m] < target) l = m + 1;
            else r = m;
        }
        return l;
    }

    static int queryLo(int v, long xv, long yv, long xt, long yt) {
        int b = base[v];
        int s = loSz[v];

        if (s <= 16) {
            for (int i = s - 1; i >= 0; --i) {
                if (cmpPrevEdge(loPrev[b + i], xv, yv, xt, yt) < 0) return loLen[b + i];
            }
            return 0;
        }

        int l = 0, r = s - 1, res = -1;
        while (l <= r) {
            int m = (l + r) >>> 1;
            if (cmpPrevEdge(loPrev[b + m], xv, yv, xt, yt) < 0) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res < 0 ? 0 : loLen[b + res];
    }

    static int queryHi(int v, long xv, long yv, long xt, long yt) {
        int b = base[v];
        int s = hiSz[v];

        if (s <= 16) {
            for (int i = s - 1; i >= 0; --i) {
                if (cmpPrevEdge(hiPrev[b + i], xv, yv, xt, yt) > 0) return hiLen[b + i];
            }
            return 0;
        }

        int l = 0, r = s - 1, res = -1;
        while (l <= r) {
            int m = (l + r) >>> 1;
            if (cmpPrevEdge(hiPrev[b + m], xv, yv, xt, yt) > 0) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return res < 0 ? 0 : hiLen[b + res];
    }

    static void insertLo(int v, int L, int prev) {
        long xv = x[v], yv = y[v];
        int b = base[v];
        int s = loSz[v];
        int pos = lowerBound(loLen, b, s, L);

        if (pos < s && loLen[b + pos] == L) {
            if (cmpPrevPrev(prev, loPrev[b + pos], xv, yv) >= 0) return;
            loPrev[b + pos] = (short) prev;
        } else {
            int move = s - pos;
            if (move > 0) {
                System.arraycopy(loLen, b + pos, loLen, b + pos + 1, move);
                System.arraycopy(loPrev, b + pos, loPrev, b + pos + 1, move);
            }
            loLen[b + pos] = (short) L;
            loPrev[b + pos] = (short) prev;
            s++;
        }

        if (pos + 1 < s && cmpPrevPrev(loPrev[b + pos + 1], loPrev[b + pos], xv, yv) <= 0) {
            int move = s - pos - 1;
            if (move > 0) {
                System.arraycopy(loLen, b + pos + 1, loLen, b + pos, move);
                System.arraycopy(loPrev, b + pos + 1, loPrev, b + pos, move);
            }
            loSz[v] = s - 1;
            return;
        }

        int left = pos - 1;
        while (left >= 0 && cmpPrevPrev(loPrev[b + left], loPrev[b + pos], xv, yv) >= 0) left--;

        int del = pos - (left + 1);
        if (del > 0) {
            int move = s - pos;
            if (move > 0) {
                System.arraycopy(loLen, b + pos, loLen, b + left + 1, move);
                System.arraycopy(loPrev, b + pos, loPrev, b + left + 1, move);
            }
            s -= del;
        }

        loSz[v] = s;
    }

    static void insertHi(int v, int L, int prev) {
        long xv = x[v], yv = y[v];
        int b = base[v];
        int s = hiSz[v];
        int pos = lowerBound(hiLen, b, s, L);

        if (pos < s && hiLen[b + pos] == L) {
            if (cmpPrevPrev(prev, hiPrev[b + pos], xv, yv) <= 0) return;
            hiPrev[b + pos] = (short) prev;
        } else {
            int move = s - pos;
            if (move > 0) {
                System.arraycopy(hiLen, b + pos, hiLen, b + pos + 1, move);
                System.arraycopy(hiPrev, b + pos, hiPrev, b + pos + 1, move);
            }
            hiLen[b + pos] = (short) L;
            hiPrev[b + pos] = (short) prev;
            s++;
        }

        if (pos + 1 < s && cmpPrevPrev(hiPrev[b + pos + 1], hiPrev[b + pos], xv, yv) >= 0) {
            int move = s - pos - 1;
            if (move > 0) {
                System.arraycopy(hiLen, b + pos + 1, hiLen, b + pos, move);
                System.arraycopy(hiPrev, b + pos + 1, hiPrev, b + pos, move);
            }
            hiSz[v] = s - 1;
            return;
        }

        int left = pos - 1;
        while (left >= 0 && cmpPrevPrev(hiPrev[b + left], hiPrev[b + pos], xv, yv) <= 0) left--;

        int del = pos - (left + 1);
        if (del > 0) {
            int move = s - pos;
            if (move > 0) {
                System.arraycopy(hiLen, b + pos, hiLen, b + left + 1, move);
                System.arraycopy(hiPrev, b + pos, hiPrev, b + left + 1, move);
            }
            s -= del;
        }

        hiSz[v] = s;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        n = fs.nextInt();
        w = n + 1;

        x = new long[w];
        y = new long[w];
        x[0] = 0;
        y[0] = 0;

        for (int i = 1; i <= n; ++i) {
            x[i] = fs.nextLong();
            y[i] = fs.nextLong();
        }

        sortPoints(1, n);

        int size = w * w;
        loLen = new short[size];
        loPrev = new short[size];
        hiLen = new short[size];
        hiPrev = new short[size];
        loSz = new int[w];
        hiSz = new int[w];
        base = new int[w];

        for (int i = 0; i < w; i++) base[i] = i * w;

        for (int i = 1; i <= n; ++i) {
            int b = base[i];
            loSz[i] = 1;
            hiSz[i] = 1;
            loLen[b] = 1;
            hiLen[b] = 1;
            loPrev[b] = 0;
            hiPrev[b] = 0;
        }

        ans = 1;

        for (int j = 1; j <= n; ++j) {
            long xj = x[j], yj = y[j];

            for (int k = j + 1; k <= n; ++k) {
                long xk = x[k], yk = y[k];
                if (xj >= xk || yj >= yk) continue;

                int bestHi = queryLo(j, xj, yj, xk, yk);
                if (bestHi != 0) {
                    int cand = bestHi + 1;
                    insertHi(k, cand, j);
                    if (cand > ans) ans = cand;
                }

                int bestLo = queryHi(j, xj, yj, xk, yk);
                if (bestLo != 0) {
                    int cand = bestLo + 1;
                    insertLo(k, cand, j);
                    if (cand > ans) ans = cand;
                }
            }
        }

        System.out.print(ans);
    }
}