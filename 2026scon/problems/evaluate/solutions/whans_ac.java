import java.io.*;

public class Main {
    static final class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

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
            do c = read(); while (c <= 32 && c != -1);

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
    }

    static int n;
    static long m;
    static long[] a;
    static long[] heap;
    static int heapSize;

    static void heapClear() {
        heapSize = 0;
    }

    static void heapPush(long x) {
        int i = ++heapSize;
        while (i > 1) {
            int p = i >> 1;
            if (heap[p] >= x) break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    static long heapPop() {
        long ret = heap[1];
        long last = heap[heapSize--];
        int i = 1;
        while ((i << 1) <= heapSize) {
            int l = i << 1;
            int r = l + 1;
            int c = l;
            if (r <= heapSize && heap[r] > heap[l]) c = r;
            if (heap[c] <= last) break;
            heap[i] = heap[c];
            i = c;
        }
        heap[i] = last;
        return ret;
    }

    static boolean judge(long x) {
        long c = 0;
        long cost = 0;
        heapClear();

        for (int i = 1; i <= n; i++) {
            if (a[i] >= x) {
                c++;
            } else {
                heapPush(a[i] - x); // negative value
                c--;
                if (c < 0) {
                    if (heapSize > 0) {
                        cost -= heapPop(); // subtract negative => add positive cost
                    } else {
                        return false;
                    }
                    c += 2;
                }
            }
        }
        return cost <= m;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();

        n = (int) fs.nextLong();
        m = fs.nextLong();

        a = new long[n + 1];
        for (int i = 1; i <= n; i++) a[i] = fs.nextLong();

        heap = new long[n + 5];

        long l = 0, r = 2_000_000_001L;
        while (l + 1 < r) {
            long mid = (l + r) >>> 1;
            if (judge(mid)) l = mid;
            else r = mid;
        }

        System.out.print(l);
    }
}