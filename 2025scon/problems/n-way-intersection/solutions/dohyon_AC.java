import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()) - 1;
        int[] A = new int[N], idx = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken()) - 1;
            idx[A[i]] = i;
        }
        int i = 0;
        long cw = idx[0], ccw = idx[N - 1];
        while (i + 1 != M) {
            cw += (idx[i + 1] - idx[i] + N) % N;
            i++;
        }
        i = N - 1;
        while (i != M) {
            ccw += (idx[(i - 1) % N] - idx[i] + N) % N;
            i = (i - 1) % N;
        }
        if (cw < ccw)
            System.out.println("CW");
        else
            System.out.println("CCW");
    }
}