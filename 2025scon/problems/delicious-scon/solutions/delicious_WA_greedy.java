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
        int[] k = new int[N + 1];
        int[][] arr = new int[N + 1][M + 1], dp = new int[N + 1][M + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            k[i] = Integer.parseInt(st.nextToken());
            for (int j = 1; j <= M; j++)
                arr[i][j] = M - Math.abs(j - k[i]);
        }
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) {
                if (j <= k[i - 1]) {
                    int s = 0, e = D / C + 1, mid;
                    while (s + 1 < e) {
                        mid = (s + e) >> 1;
                        if (j + C * mid <= k[i - 1])
                            s = mid;
                        else
                            e = mid;
                    }
                    dp[i][j] = arr[i][j] + dp[i - 1][j + C * s];
                } else {
                    int s = 0, e = D / C + 1, mid;
                    while (s + 1 < e) {
                        mid = (s + e) >> 1;
                        if (k[i - 1] <= j - C * mid)
                            s = mid;
                        else
                            e = mid;
                    }
                    dp[i][j] = arr[i][j] + dp[i - 1][j - C * s];
                }
            }
        int ans = 0;
        for (int j = 1; j <= M; j++)
            ans = Integer.max(ans, dp[N][j]);
        System.out.println(ans);
    }
}