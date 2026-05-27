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
        if (N == 3) {
            System.out.print("-2 0 2");
            return;
        }
        int[] ans = new int[N + 1];
        for (int i = 1; i < N; i += 2) {
            ans[i] = (i + 1) >> 1;
            ans[i + 1] = -ans[i];
        }
        for (int i = 0; i < N; i++)
            sb.append(ans[i]).append(' ');
        System.out.print(sb);
    }
}