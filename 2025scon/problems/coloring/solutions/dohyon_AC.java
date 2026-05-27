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
        int n = Integer.parseInt(br.readLine());
        list = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            list[i] = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
            list[u].add(v);
            list[v].add(u);
        }
        int[] col = new int[n + 1];
        for (int i = 2; i <= n; i++)
            col[i] = -1;
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.addLast(1);
        while (!q.isEmpty()) {
            int cur = q.removeFirst();
            for (int next : list[cur])
                if (col[next] == -1) {
                    col[next] = col[cur] ^ 1;
                    q.addLast(next);
                } else if (col[next] == col[cur]) {
                    System.out.println(3);
                    return;
                }
        }
        System.out.println(2);
    }
}