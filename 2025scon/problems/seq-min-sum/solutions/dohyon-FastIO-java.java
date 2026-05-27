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
        int[] a = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            a[i] = Integer.parseInt(st.nextToken());
        int min = a[N];
        long sum = a[N];
        for (int i = N - 1; i >= 1; i--) {
            min = Integer.min(min, a[i]);
            sum += min;
        }
        System.out.println(sum);
    }
}