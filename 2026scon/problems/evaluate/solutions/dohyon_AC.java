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
        int N = Integer.parseInt(st.nextToken()), B = Integer.parseInt(st.nextToken());
        int[] A = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++)
            A[i] = Integer.parseInt(st.nextToken());
        long s = 0, e = (long) 2e9 + 2, m;
        while (s + 1 < e) {
            m = (s + e) >> 1;
            int credit = 0;
            long b = 0;
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
            for (int i = 1; i <= N; i++)
                if (A[i] >= m)
                    ++credit;
                else {
                    pq.add(A[i]);
                    if (credit == 0) {
                        ++credit;
                        b += m - pq.poll();
                    } else
                        --credit;
                }
            if (b <= B)
                s = m;
            else
                e = m;
        }
        System.out.println(s);
    }
}