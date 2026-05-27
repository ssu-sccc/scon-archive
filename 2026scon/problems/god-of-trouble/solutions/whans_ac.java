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

    static int n, c;
    static int[] A;
    static int sameIdx, diffIdx;

    static int ask(int i) throws Exception {
        out.println("? " + i);
        out.flush();
        int x = fs.nextInt();
        c++;
        return x;
    }

    static void answer() {
        StringBuilder sb = new StringBuilder();
        sb.append("! ");
        for (int i = 1; i <= n; i++) {
            if (i > 1) sb.append(' ');
            sb.append(A[i]);
        }
        out.println(sb);
        out.flush();
    }

    static void flip() {
        for (int i = 1; i <= n; i++) {
            if (A[i] != -1) A[i] ^= 1;
        }
    }

    static void rev() {
        for (int l = 1, r = n; l < r; l++, r--) {
            int tmp = A[l];
            A[l] = A[r];
            A[r] = tmp;
        }
    }

    static void queryPair(int i) throws Exception {
        A[i] = ask(i);
        A[n - i + 1] = ask(n - i + 1);

        if ((A[i] ^ A[n - i + 1]) != 0) {
            if (diffIdx == -1) diffIdx = i;
        } else {
            if (sameIdx == -1) sameIdx = i;
        }
    }

    static void solve() throws Exception {
        n = fs.nextInt();
        c = 0;
        A = new int[n + 1];
        Arrays.fill(A, -1);
        sameIdx = -1;
        diffIdx = -1;

        for (int i = 1; i <= n - i + 1; i++) {
            if (i < n - i + 1) {
                queryPair(i);
            } else {
                A[i] = ask(i);
            }

            if (c % 10 == 0) {
                if (sameIdx == -1) {
                    int op = ask(diffIdx);
                    op = ask(diffIdx);
                    if (A[diffIdx] != op) flip();
                } else if (diffIdx == -1) {
                    int op = ask(sameIdx);
                    op = ask(sameIdx);
                    if (A[sameIdx] != op) flip();
                } else {
                    int op1 = ask(diffIdx);
                    int op2 = ask(sameIdx);

                    if (A[sameIdx] == op2 && A[diffIdx] != op1) {
                        rev();
                    } else if (A[sameIdx] != op2 && A[diffIdx] != op1) {
                        flip();
                    } else if (A[sameIdx] != op2 && A[diffIdx] == op1) {
                        rev();
                        flip();
                    }
                }
            }
        }

        answer();
    }

    public static void main(String[] args) throws Exception {
        int T = 1;
        while (T-- > 0) solve();
    }
}