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
        String T = br.readLine();
        int CJS = 0, JCS = 0;
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j <= N; j++) {
                if ((i == 0 || T.charAt(i - 1) == 'S') && T.charAt(j - 1) == 'S') {
                    String S = T.substring(i, j);
                    if (S.contains("SC") || S.contains("SJ") || S.contains("SS"))
                        continue;
                    boolean chk1 = S.contains("CJ"), chk2 = S.contains("JC");
                    if (chk1 && !chk2)
                        ++CJS;
                    else if (!chk1 && chk2)
                        ++JCS;
                }
            }
        System.out.printf("%d\n%d", CJS, JCS);
    }
}