import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static ArrayList<Integer>[] list;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), Q = Integer.parseInt(st.nextToken());
        list = new ArrayList[N + 1];
        HashMap<Integer, Integer>[] H = new HashMap[N + 1];
        for (int i = 1; i <= N; i++) {
            list[i] = new ArrayList<>();
            H[i] = new HashMap<>();
        }
        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
            list[u].add(v);
            list[v].add(u);
        }
        for (int i = 1; i <= N; i++)
            for (int j : list[i])
                H[i].put(list[j].size(), H[i].getOrDefault(list[j].size(), 0) + 1);
        long[] sum = new long[N];
        for (; Q > 0; Q--) {
            st = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(st.nextToken());
            if (op == 1) {
                int i = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
                for (int deg : H[i].keySet())
                    sum[deg] += (long) H[i].get(deg) * x;
            } else {
                int d = Integer.parseInt(st.nextToken());
                sb.append(sum[d]).append('\n');
            }
        }
        System.out.print(sb);
    }
}