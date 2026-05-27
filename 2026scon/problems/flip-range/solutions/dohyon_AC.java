import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int solve(char[] T, char[] S) {
        int ans = 0;
        boolean chk = true;
        for (int i = 0; i < T.length; i++)
            if (T[i] == S[i])
                chk = true;
            else if (chk) {
                ++ans;
                chk = false;
            }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        char[] T = br.readLine().toCharArray();
        char[] S1 = new char[N], S2 = new char[N];
        for (int i = 0; i < N; i++)
            if ((i & 1) == 0) {
                S1[i] = '0';
                S2[i] = '1';
            } else {
                S1[i] = '1';
                S2[i] = '0';
            }
        System.out.println(Integer.min(solve(T, S1), solve(T, S2)));
    }
}