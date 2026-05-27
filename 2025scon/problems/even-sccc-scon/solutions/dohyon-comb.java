import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long MOD = 1000000007;
    static long[] fac;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static long pow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    static long C(int n, int r) {
        return fac[n] * pow(fac[n - r] * fac[r] % MOD, MOD - 2) % MOD;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] pow2 = new long[N + 1], pow24 = new long[N + 1];
        fac = new long[N + 1];
        fac[0] = pow2[0] = pow24[0] = 1;
        for (int i = 1; i <= N; i++) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
            pow24[i] = pow24[i - 1] * 24 % MOD;
            fac[i] = fac[i - 1] * i % MOD;
        }
        long sum = 0;
        for (int even = 0; even <= N; even += 2) {
            sum += (pow2[even] * pow24[N - even] % MOD) * C(N, even) % MOD;
            sum %= MOD;
        }
        System.out.println(sum);
    }
}