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
        int[] b = new int[N+1];
        int[][] dp = new int[N + 1][M + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            b[i] = Integer.parseInt(st.nextToken());
        for(int i=1;i<=N;i++) {
            for (int s = 1; s <= C; s++) {
                multiset S = new multiset();
                for (int j = s; j - D <= M; j += C) {
                    if (j <= M) S.add(dp[i - 1][j]);
                    if (j - D >= 1) dp[i][j - D] = S.max();
                    if (j - D - D >= 1) S.remove(dp[i - 1][j - D - D]);
                }
            }
            for (int j = 1; j <= M; j++) dp[i][j] += M - Math.abs(b[i] - j);
        }
        int ans = 0;
        for (int j = 1; j <= M; j++)
            ans = Integer.max(ans, dp[N][j]);
        System.out.println(ans);
    }
}

class multiset {
    TreeMap<Integer, Integer> map = new TreeMap<>();

    void add(int i) {
        map.put(i, map.getOrDefault(i, 0) + 1);
    }

    void remove(int i) {
        if (!map.containsKey(i))
            return;
        int cnt = map.get(i);
        if (cnt == 1)
            map.remove(i);
        else
            map.put(i, cnt - 1);
    }

    int max() {
        return map.lastKey();
    }
}