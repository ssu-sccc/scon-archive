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
        ArrayList<Pair> L = new ArrayList<>();
        for (int i = 0; i < N; i++)
            if (L.isEmpty() || T.charAt(i - 1) != T.charAt(i))
                L.add(new Pair(T.charAt(i), 1));
            else
                ++L.get(L.size() - 1).len;
        for (int i = 0; i < L.size(); i++)
            if (i == L.size() - 1 || L.get(i).c > L.get(i + 1).c)
                sb.append(L.get(i).c);
            else {
                for (int len = L.get(i).len; len > 0; len--)
                    sb.append(L.get(i).c);
            }
        System.out.print(sb);
    }
}

class Pair {
    char c;
    int len;

    Pair(char c, int len) {
        this.c = c;
        this.len = len;
    }
}