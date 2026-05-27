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
        PriorityQueue<Pair>[] pq = new PriorityQueue[C + 1];
        for (int j = 1; j <= C; j++)
            pq[j] = new PriorityQueue<>();
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= C; j++) {
                for (int idx = j; idx - D <= M; idx += C) {
                    if (idx <= M)
                        pq[j].add(new Pair(dp[i - 1][idx], idx));
                    if (idx - D >= 1) {
                        while (!pq[j].isEmpty() && pq[j].peek().idx < idx - D - D)
                            pq[j].poll();
                        dp[i][idx - D] = Integer.max(dp[i][idx - D], pq[j].peek().val + arr[i][idx - D]);
                    }
                }
                pq[j].clear();
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