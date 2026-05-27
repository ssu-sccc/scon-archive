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
        int[] A = new int[N + 1], B = new int[N + 1];
        long[] sum = new long[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            A[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            B[i] = Integer.parseInt(st.nextToken());
            sum[i] = sum[i - 1] + (A[i] == 0 ? -1 : 1) * B[i];
        }
        int M = 1;
        long S = sum[1];
        for (int i = 2; i <= N; i++) {
            if (0 < (M + 1) * (sum[N] - sum[i - 1]))
                M++;
            S += M * (sum[i] - sum[i - 1]);
        }
        System.out.printf("%d %d", M, S);
    }
}