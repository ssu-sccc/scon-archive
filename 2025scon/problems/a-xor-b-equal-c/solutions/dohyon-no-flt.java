import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long MOD = 1000000007;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static long pow(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    static long solve(int a, int b) {
        if (a % 2 != 0 || (b - a / 2) < 0 || (b - a / 2) % 3 != 0)
            return 0;
        int n = (a + b) / 3, k = a / 2;
        int[] sp = new int[n + 1];
        for (int i = 1; i <= n; i++)
            sp[i] = i;
        for (int i = 2; i * i <= n; i++)
            if (sp[i] == i)
                for (int j = 2; i * j <= n; j++)
                    sp[i * j] = i;
        long ans = 1;
        for (int i = k; i > 0; i--)
            ans = (ans * 3) % MOD;
        int[] cnt = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int tmp = i;
            while (tmp != 1) {
                cnt[sp[tmp]]++;
                tmp /= sp[tmp];
            }
        }
        for (int i = 1; i <= k; i++) {
            int tmp = i;
            while (tmp != 1) {
                cnt[sp[tmp]]--;
                tmp /= sp[tmp];
            }
        }
        for (int i = 1; i <= n - k; i++) {
            int tmp = i;
            while (tmp != 1) {
                cnt[sp[tmp]]--;
                tmp /= sp[tmp];
            }
        }
        for (int i = 1; i <= n; i++)
            ans = ans * pow(i, cnt[i]) % MOD;
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        System.out.println(solve(a, b));
    }
}