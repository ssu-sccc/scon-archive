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
        ArrayDeque<Pair>[] dqL = new ArrayDeque[C], dqR = new ArrayDeque[C];
        for (int j = 0; j < C; j++) {
                dqL[j] = new ArrayDeque<>();
                dqR[j] = new ArrayDeque<>();
            }
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j < C; j++) {
                dqL[j].clear();
                dqR[j].clear();
            }
            for (int j = 1; j <= M; j++) {
                int idx = j % C;
                while (!dqL[idx].isEmpty() && Math.abs(j - dqL[idx].getFirst().idx) > D)
                    dqL[idx].removeFirst();
                while (!dqL[idx].isEmpty() && dqL[idx].getLast().val <= dp[i - 1][j])
                    dqL[idx].removeLast();
                dqL[idx].addLast(new Pair(dp[i - 1][j], j));
                dp[i][j] = Integer.max(dp[i][j], dqL[idx].getFirst().val + arr[i][j]);
            }
            for (int j = M; j >= 1; j--) {
                int idx = j % C;
                while (!dqR[idx].isEmpty() && Math.abs(j - dqR[idx].getFirst().idx) > D)
                    dqR[idx].removeFirst();
                while (!dqR[idx].isEmpty() && dqR[idx].getLast().val <= dp[i - 1][j])
                    dqR[idx].removeLast();
                dqR[idx].addLast(new Pair(dp[i - 1][j], j));
                dp[i][j] = Integer.max(dp[i][j], dqR[idx].getFirst().val + arr[i][j]);
            }
        }
        int ans = 0;
        for (int j = 1; j <= M; j++)
            ans = Integer.max(ans, dp[N][j]);
        System.out.println(ans);
    }
}

class Pair {
    int val, idx;

    Pair(int val, int idx) {
        this.val = val;
        this.idx = idx;
    }
}