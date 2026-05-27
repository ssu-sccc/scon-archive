import java.io.*;
import java.util.*;

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

        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c;
            do {
                c = read();
            } while (c <= 32 && c != -1);

            while (c > 32) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }

        int nextInt() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= 32 && c != -1);

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

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        StringBuilder out = new StringBuilder();

        int n = fs.nextInt();
        String t = fs.next();

        char[] str = t.toCharArray();

        char[] ch = new char[n];
        int[] cnt = new int[n];
        int m = 0;

        for (int s = 0, e = 0; s < n; s = e) {
            while (e < n && str[s] == str[e]) e++;
            ch[m] = str[s];
            cnt[m] = e - s;
            m++;
        }

        for (int i = 1; i < m; i++) {
            if (ch[i - 1] > ch[i]) cnt[i - 1] = 1;
        }
        cnt[m-1] = 1;

        StringBuilder ans = new StringBuilder(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                ans.append(ch[i]);
            }
        }

        out.append(ans).append('\n');
        System.out.print(out);
    }
}