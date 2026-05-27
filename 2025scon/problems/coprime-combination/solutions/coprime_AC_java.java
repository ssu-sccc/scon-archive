import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] isp = new int[5050];
        for (int i = 1; i < isp.length; i++)
            isp[i] = i;
        for (int i = 2; i * i < isp.length; i++)
            if (isp[i] == i)
                for (int j = 2; i * j < isp.length; j++)
                    isp[i * j] = i;
        int[][] cnt = new int[5050][5050];
        for (int i = 2; i < cnt.length; i++) {
            for (int j = 2; j < cnt[i].length; j++)
                cnt[i][j] = cnt[i - 1][j];
            int tmp = i;
            while (isp[tmp] != 1) {
                cnt[i][isp[tmp]]++;
                tmp /= isp[tmp];
            }
        }
        for (int T = Integer.parseInt(br.readLine()); T > 0; T--) {
            st = new StringTokenizer(br.readLine());
            int n1 = Integer.parseInt(st.nextToken()), r1 = Integer.parseInt(st.nextToken());
            int n2 = Integer.parseInt(st.nextToken()), r2 = Integer.parseInt(st.nextToken());
            boolean check = true;
            for (int i = 2; i < 5000; i++)
                if (cnt[n1][i] - cnt[n1 - r1][i] - cnt[r1][i] > 0 && cnt[n2][i] - cnt[n2 - r2][i] - cnt[r2][i] > 0) {
                    check = false;
                    break;
                }
            sb.append(check ? 1 : 0).append('\n');
        }
        System.out.print(sb);
    }
}