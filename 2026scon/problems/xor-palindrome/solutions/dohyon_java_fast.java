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
        int[] half = new int[N + 1], cnt = new int[1 << m];
        for (int i = 1; i <= N; i++) {
            String S = br.readLine();
            for (int j = 0; j < m; j++) {
                half[i] <<= 1;
                half[i] |= S.charAt(j) == S.charAt(M - 1 - j) ? 0 : 1;
            }
            cnt[half[i]]++;
        }
        int MAX = 1 << m;
        long[] two = new long[N + 1], dp = new long[MAX];
        two[0] = 1;
        for (int i = 1; i <= N; i++)
            two[i] = (two[i - 1] * 2) % MOD;
        dp[0] = 1;
        for (int i = 0; i < MAX; i++) {
            if (cnt[i] == 0)
                continue;
            long[] tmp = new long[MAX];
            for (int j = 0; j < MAX; j++) {
                tmp[j] += dp[j] * two[cnt[i] - 1] % MOD;
                tmp[j] %= MOD;
                tmp[i ^ j] += dp[j] * two[cnt[i] - 1] % MOD;
                tmp[i ^ j] %= MOD;
            }
            for (int j = 0; j < MAX; j++)
                dp[j] = tmp[j];
        }
        System.out.println((dp[0] + MOD - 1) % MOD);
    }
}