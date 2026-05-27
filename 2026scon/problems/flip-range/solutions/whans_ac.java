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

        String next() throws IOException {
            int c;
            do c = read(); while (c <= 32 && c != -1);

            StringBuilder sb = new StringBuilder();
            while (c > 32) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }
    }

    static int calc(char[] t, int startBit) {
        int n = t.length;
        int cnt = 0;
        boolean prevMismatch = false;

        for (int i = 0; i < n; i++) {
            char expected = ((i & 1) == 0)
                    ? (char) ('0' + startBit)
                    : (char) ('0' + (startBit ^ 1));

            boolean mismatch = (t[i] != expected);
            if (mismatch && !prevMismatch) cnt++;
            prevMismatch = mismatch;
        }
        return cnt;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();

        int n = fs.nextInt();
        char[] t = fs.next().toCharArray();

        int ans = Math.min(calc(t, 0), calc(t, 1));
        System.out.print(ans);
    }
}