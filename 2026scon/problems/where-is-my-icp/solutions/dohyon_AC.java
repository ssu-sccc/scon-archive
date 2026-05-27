import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[] cnt = new int[256];
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static void use(String L) {
        for (int i = 0; i < L.length(); i++)
            ++cnt[L.charAt(i)];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String S = br.readLine();
        int M = Integer.parseInt(br.readLine());
        String T = br.readLine();
        use(S);
        use(T);
        if (cnt['I'] >= 1 && cnt['C'] >= 2 && cnt['P'] >= 1)
            System.out.println("m4us happy");
        else
            System.out.println("m4us sad");
    }
}