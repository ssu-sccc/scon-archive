import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] L = new int[3];
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int solve(int idx, int t, int H) {
        if (idx == 3)
            return 1 <= H ? t : 600;
        return Integer.min(solve(idx + 1, t + L[idx], H), solve(idx + 1, t + L[idx] / 2, H - L[idx] / 2));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 3; i++)
            L[i] = Integer.parseInt(st.nextToken());
        int H = Integer.parseInt(br.readLine());
        System.out.println(solve(0, 0, H));
    }
}