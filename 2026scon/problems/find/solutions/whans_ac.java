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
    }

    static FastScanner fs = new FastScanner();
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    static int ask(int l, int r) throws Exception {
        StringBuilder sb = new StringBuilder();
        sb.append("? ").append(r - l + 1).append(' ');
        for (int i = l; i <= r; i++) sb.append(i).append(' ');
        out.println(sb.toString());
        out.flush();
        return fs.nextInt();
    }

    public static void main(String[] args) throws Exception {
        int n = fs.nextInt();

        int l = 0, r = n;
        while (l + 1 < r) {
            int m = (l + r) >>> 1;
            if (ask(1, m) != 0) r = m;
            else l = m;
        }

        int L = 1, R = n + 1;
        while (L + 1 < R) {
            int M = (L + R) >>> 1;
            if (ask(M, n) != 0) L = M;
            else R = M;
        }

        out.println("! " + r + " " + L);
        out.flush();
    }
}