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
        long[] A = new long[N + 1], B = new long[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            A[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            B[i] = Integer.parseInt(st.nextToken());
        ArrayList<Integer> L = new ArrayList<>();
        for (int i = 1; i <= N; i++)
            L.add(i);
        L.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                long l = B[o1] * A[o2], r = B[o2] * A[o1];
                return l == r ? o2 - o1 : Long.compare(r, l);
            }
        });
        System.out.println(L.get(0));
    }
}