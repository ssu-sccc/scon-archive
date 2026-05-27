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

        int nextInt() throws IOException {
            int c;
            do c = read(); while (c <= 32 && c != -1);

            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            int val = 0;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
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
    static long[] A, B;
    static int[] I;

    static int cmp(int a, int b) {
        long lhs = B[a] * A[b];
        long rhs = B[b] * A[a];
        if (lhs == rhs) return Integer.compare(a, b);
        return lhs < rhs ? -1 : 1;
    }

    static void sort(int l, int r) {
        int i = l, j = r;
        int pivot = I[(l + r) >>> 1];

        while (i <= j) {
            while (cmp(I[i], pivot) < 0) i++;
            while (cmp(I[j], pivot) > 0) j--;
            if (i <= j) {
                int tmp = I[i];
                I[i] = I[j];
                I[j] = tmp;
                i++;
                j--;
            }
        }
        if (l < j) sort(l, j);
        if (i < r) sort(i, r);
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();

        n = fs.nextInt();
        A = new long[n + 1];
        B = new long[n + 1];
        I = new int[n];

        for (int i = 1; i <= n; i++) {
            A[i] = fs.nextLong();
            I[i - 1] = i;
        }
        for (int i = 1; i <= n; i++) {
            B[i] = fs.nextLong();
            I[i - 1] = i;
        }

        sort(0, n - 1);

        StringBuilder sb = new StringBuilder();
        sb.append(I[n-1]);
        sb.append('\n');
        System.out.print(sb);
    }
}