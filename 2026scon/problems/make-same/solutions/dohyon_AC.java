import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static boolean solve(long sum, long tmp) {
        if (sum % N != 0)
            return false;
        long g = sum / N;
        return tmp == g * N * (N + 1) / 2;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        long[] A = new long[N + 1];
        st = new StringTokenizer(br.readLine());
        long sum = 0, tmp = 0;
        for (int i = 1; i <= N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            sum += A[i];
            tmp += A[i] * i;
        }
        sb.append(solve(sum, tmp) ? "Yes\n" : "No\n");
        for (int Q = Integer.parseInt(br.readLine()); Q > 0; Q--) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
            sum += x - A[i];
            tmp += (x - A[i]) * i;
            A[i] = x;
            sb.append(solve(sum, tmp) ? "Yes\n" : "No\n");
        }
        System.out.print(sb);
    }
}