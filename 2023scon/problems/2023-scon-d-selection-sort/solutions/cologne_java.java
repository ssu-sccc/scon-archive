import java.io.*;
import java.util.Arrays;

public class Main {

    static class Tree {
        int[] idx;
        int N;

        Tree(int[] A) {
            N = 1;
            while (N < A.length) {
                N *= 2;
            }
            idx = new int[2 * N];
            for (int i = 0; i < 2 * N; i++) {
                idx[i] = Integer.MAX_VALUE;
            }
            System.arraycopy(A, 0, idx, N, A.length);
            for (int i = N - 1; i > 0; i--) {
                idx[i] = Math.min(idx[2 * i], idx[2 * i + 1]);
            }
        }

        void set(int i, int v) {
            i += N;
            idx[i] = v;
            while (i > 1) {
                i /= 2;
                idx[i] = Math.min(idx[2 * i], idx[2 * i + 1]);
            }
        }

        int get(int i) {
            return idx[i + N];
        }

        int minIdx() {
            int i = 1;
            while (i < N) {
                if (idx[2 * i] < idx[2 * i + 1]) {
                    i = 2 * i;
                } else {
                    i = 2 * i + 1;
                }
            }
            return i - N;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(reader.readLine().trim());
        int[] A = Arrays.stream(reader.readLine().split("\\s+")).mapToInt(Integer::parseInt).map(x -> x - 1).toArray();
        Tree T = new Tree(A);
        int[] ans = new int[N];
        for (int i = 0; i < N; i++) {
            int j = T.minIdx();
            ans[T.get(i)] += j - i;
            ans[T.get(j)] += j - i;
            T.set(j, T.get(i));
            T.set(i, Integer.MAX_VALUE);
        }
        for (int a : ans) {
            writer.write(a + " ");
        }
        writer.write("\n");
        writer.flush();
    }
}
