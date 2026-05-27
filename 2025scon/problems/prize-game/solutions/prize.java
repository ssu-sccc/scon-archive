import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] cnt = new int[101];
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken()), n2 = Integer.parseInt(st.nextToken()), n3 = Integer.parseInt(st.nextToken());
            cnt[n1]++;
            cnt[n2]++;
            cnt[n3]++;
        }
        int ans = 0;
        for (int n1 = 1; n1 <= 100; n1++) {
            cnt[n1]++;
            for (int n2 = n1 + 1; n2 <= 100; n2++) {
                cnt[n2]++;
                for (int n3 = n2 + 1; n3 <= 100; n3++) {
                    cnt[n3]++;
                    for (int i = 100; i >= 1; i--)
                        if (cnt[i] == 1) {
                            if (i == n1 || i == n2 || i == n3)
                                ans++;
                            break;
                        }
                    cnt[n3]--;
                }
                cnt[n2]--;
            }
            cnt[n1]--;
        }
        System.out.println(ans);
    }
}