import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] list;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    private static int read() throws IOException {
        int n = 0, i;
        boolean isNegative = false;
        while ((i = System.in.read()) <= 32) {
            if (i == -1) return -1;
        }
        if (i == '-') {
            isNegative = true;
            i = System.in.read();
        }
        do {
            n = (n << 3) + (n << 1) + (i & 15);
        } while ((i = System.in.read()) >= '0');

        return isNegative ? -n : n;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = read(), M = read(), Q = read();
        list = new ArrayList[N + 1];
        HashMap<Integer, Integer>[] H = new HashMap[N + 1];
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
            H[i] = new HashMap<>();
        }
        for (int i = 1; i <= M; i++) {
            int u = read(), v = read();
            list[u].add(v);
            list[v].add(u);
        }
        for (int i = 1; i <= N; i++)
            for (int j : list[i])
                H[i].put(list[j].size(), H[i].getOrDefault(list[j].size(), 0) + 1);
        long[] sum = new long[N];
        for (; Q > 0; Q--) {
            int op = read();
            if (op == 1) {
                int i = read(), x = read();
                for (int deg : H[i].keySet())
                    sum[deg] += (long) H[i].get(deg) * x;
            } else {
                int d = read();
                sb.append(sum[d]).append('\n');
            }
        }
        System.out.print(sb);
    }
}