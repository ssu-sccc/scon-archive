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
            do c = read(); while (c <= ' ');

            long sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            long x = 0;
            while (c > ' ') {
                x = x * 10 + (c - '0');
                c = read();
            }
            return x * sign;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        StringBuilder out = new StringBuilder();

        int n = fs.nextInt();
        long[] a = new long[n + 1];

        long sum = 0;
        long w = 0;

        for (int i = 1; i <= n; i++) {
            a[i] = fs.nextLong();
            sum += a[i];
            w += (long) i * a[i];
        }

        appendAnswer(out, sum, w, n);

        int q = fs.nextInt();
        for (int t = 0; t < q; t++) {
            int i = fs.nextInt();
            long x = fs.nextLong();

            sum += x - a[i];
            w += (long) i * (x - a[i]);
            a[i] = x;

            appendAnswer(out, sum, w, n);
        }

        System.out.print(out);
    }

    static void appendAnswer(StringBuilder out, long sum, long w, int n) {
        if (sum % n != 0) {
            out.append("No\n");
            return;
        }
        long x = sum / n;
        long target = x * n * (n + 1L) / 2L;
        out.append(w == target ? "Yes\n" : "No\n");
    }
}