import java.io.*;
import java.util.*;

public class Main {
    static int n, trie[][] = new int[12020020][2], c[] = new int[12020020], cnt;
    static long a[] = new long[200200];

    static int dfs(int u, int left) {
        if (u == 0) return 0;
        if (c[u] < left) return -n;

        int L = trie[u][0], R = trie[u][1];
        if (L == 0 && R == 0) return c[u] - left;
        if (c[u] == left) return 0;

        if (L == 0) return dfs(R, left + 1) + 1;
        if (R == 0) return dfs(L, left + 1) + 1;

        return Math.max(dfs(L, Math.max(0, left + 1 - c[R])), dfs(R, Math.max(0, left + 1 - c[L]))) + 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) a[i] = Long.parseLong(st.nextToken());

        for (int i = 1; i <= n; i++) {
            int u = 0;
            c[u]++;
            for (int j = 0; j < 60; j++) {
                int x = (int) ((a[i] >> j) & 1);
                if (trie[u][x] == 0) trie[u][x] = ++cnt;
                u = trie[u][x];
                c[u]++;
            }
        }

        System.out.println(Math.max(dfs(trie[0][1], 0), dfs(trie[0][0], 0)));
    }
}