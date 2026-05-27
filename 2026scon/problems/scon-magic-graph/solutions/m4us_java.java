import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024 * 64];
        private int head = 0, tail = 0;

        public FastScanner(InputStream stream) {
            this.stream = stream;
        }

        private int read() {
            if (head >= tail) {
                head = 0;
                try {
                    tail = stream.read(buf, 0, buf.length);
                } catch (IOException e) {
                    return -1;
                }
                if (tail <= 0) return -1;
            }
            return buf[head++];
        }

        public int nextInt() {
            int c = read();
            while (c <= 32) {
                if (c == -1) return -1;
                c = read();
            }
            int res = 0;
            while (c > 32) {
                res = res * 10 + c - '0';
                c = read();
            }
            return res;
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        int Q = sc.nextInt();

        int MAX_SIZE = 101010;
        
        long[] A = new long[MAX_SIZE];
        int[] DD = new int[N + 1];
        
        ArrayList<Integer>[] G = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            G[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            G[u].add(v);
            G[v].add(u);
            DD[u]++;
            DD[v]++;
        }

        HashMap<Integer, Integer>[] D = new HashMap[N + 1];
        for (int i = 1; i <= N; i++) {
            D[i] = new HashMap<>();
            for (int j : G[i]) {
                int deg = DD[j];
                D[i].put(deg, D[i].getOrDefault(deg, 0) + 1);
            }
        }

        StringBuilder out = new StringBuilder();
        for (int i = 0; i < Q; i++) {
            int op = sc.nextInt();
            if (op == 1) {
                int u = sc.nextInt();
                long x = sc.nextInt();
                
                for (Map.Entry<Integer, Integer> entry : D[u].entrySet()) {
                    int d = entry.getKey();
                    long cnt = entry.getValue();
                    A[d] += x * cnt;
                }
            } else {
                int d = sc.nextInt();
                out.append(A[d]).append('\n');
            }
        }
        
        System.out.print(out);
    }
}