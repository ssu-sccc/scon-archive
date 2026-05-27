import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
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
            do c = read();
            while (c <= ' ' && c != -1);

            long sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            long val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        long n = fs.nextLong();

        int lim = (int)(2 * n);
        boolean[] composite = new boolean[lim + 1];

        for (int s = 2; s <= lim; s++) {
            if (!composite[s]) {
                if ((long)s * s <= lim) {
                    for (int e = s * s; e <= lim; e += s) {
                        composite[e] = true;
                    }
                }
            }
        }

        int k = 0;
        for (int s = (int)n + 1; s <= lim; s++) {
            if (!composite[s]) {
                k = s;
                break;
            }
        }

        long[] S = new long[(int)n + 1];
        for (int s = 1; s <= n; s++) {
            S[s] = 2L * k * s + (1L * s * s) % k;
        }

        StringBuilder sb = new StringBuilder();
        for (int s = 1; s <= n; s++) {
            sb.append(S[s] - S[s - 1]);
            if (s != n) sb.append(' ');
        }
        sb.append('\n');
        System.out.print(sb);
    }
}