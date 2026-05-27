import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long MOD = 1000000007;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] dpO = new long[N + 1], dpE = new long[N + 1];
        dpE[0] = 1;
        for (int i = 1; i <= N; i++) {
            dpO[i] = (dpE[i - 1] * 2 % MOD + dpO[i - 1] * 24 % MOD) % MOD;
            dpE[i] = (dpO[i - 1] * 2 % MOD + dpE[i - 1] * 24 % MOD) % MOD;
        }
        System.out.println(dpE[N]);
    }
}