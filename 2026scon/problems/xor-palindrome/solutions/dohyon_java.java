import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long MOD = (long) 1e9 + 7;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        int m = M >> 1;
        int[] half = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            String S = br.readLine();
            for (int j = 0; j < m; j++) {
                half[i] <<= 1;
                half[i] |= S.charAt(j) == S.charAt(M - 1 - j) ? 0 : 1;
            }
        }
        long[][] dp = new long[N + 1][1 << m];
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < dp[i].length; j++)
                dp[i][j] = dp[i - 1][j];
            dp[i][half[i]] = (dp[i][half[i]] + 1) % MOD;
            for (int j = 0; j < dp[i].length; j++)
                dp[i][j ^ half[i]] = (dp[i][j ^ half[i]] + dp[i - 1][j]) % MOD;
        }
        System.out.println(dp[N][0]);
    }
}