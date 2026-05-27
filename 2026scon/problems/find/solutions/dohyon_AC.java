import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int x = 0, y = 0;
        int s = 0, e = n, m;
        while (s + 1 < e) {
            m = (s + e) >> 1;
            sb = new StringBuilder();
            sb.append('?').append(' ').append(m - 1 + 1);
            for (int i = 1; i <= m; i++)
                sb.append(' ').append(i);
            System.out.println(sb);
            if (br.readLine().charAt(0) == '1')
                e = m;
            else
                s = m;
        }
        x = e;
        s = x;
        e = n;
        while (s + 1 < e) {
            m = (s + e) >> 1;
            sb = new StringBuilder();
            sb.append('?').append(' ').append(m - x);
            for (int i = x + 1; i <= m; i++)
                sb.append(' ').append(i);
            System.out.println(sb);
            if (br.readLine().charAt(0) == '1')
                e = m;
            else
                s = m;
        }
        y = e;
        System.out.printf("! %d %d\n", x, y);
    }
}