import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), C = Integer.parseInt(st.nextToken()), D = Integer.parseInt(st.nextToken());
        int[][] arr = new int[N + 1][M + 1], dp = new int[N + 1][M + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int k = Integer.parseInt(st.nextToken());
            for (int j = 1; j <= M; j++)
                arr[i][j] = M - Math.abs(j - k);
        }
        for (int j = 1; j <= M; j++)
            dp[1][j] = arr[1][j];
        PriorityQueue<Pair>[] pqL = new PriorityQueue[C], pqR = new PriorityQueue[C];
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < C; j++) {
                pqL[j] = new PriorityQueue<>();
                pqR[j] = new PriorityQueue<>();
            }
            for (int j = 1; j <= M; j++) {
                int idx = j % C;
                pqL[idx].add(new Pair(dp[i - 1][j], j));
                while (!pqL[idx].isEmpty() && Math.abs(j - pqL[idx].peek().idx) > D)
                    pqL[idx].poll();
                dp[i][j] = Integer.max(dp[i][j], pqL[idx].peek().val + arr[i][j]);
            }
            for (int j = M; j >= 1; j--) {
                int idx = j % C;
                pqR[idx].add(new Pair(dp[i - 1][j], j));
                while (!pqR[idx].isEmpty() && Math.abs(j - pqR[idx].peek().idx) > D)
                    pqR[idx].poll();
                dp[i][j] = Integer.max(dp[i][j], pqR[idx].peek().val + arr[i][j]);
            }
        }
        int ans = 0;
        for (int j = 1; j <= M; j++)
            ans = Integer.max(ans, dp[N][j]);
        System.out.println(ans);
    }
}

class Pair implements Comparable<Pair> {
    int val, idx;

    Pair(int val, int idx) {
        this.val = val;
        this.idx = idx;
    }

    @Override
    public int compareTo(Pair o) {
        return o.val - this.val;
    }
}