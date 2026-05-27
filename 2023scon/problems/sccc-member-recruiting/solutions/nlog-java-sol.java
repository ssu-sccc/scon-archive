import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(bf.readLine());
        int n, k, x;
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        int[][] vec = new int[n + 1][];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(bf.readLine());
            int c = Integer.parseInt(st.nextToken());
            vec[i] = new int[c];
            for (int j = 0; j < c; j++) {
                int b = Integer.parseInt(st.nextToken());
                vec[i][j] = b - 1;
            }
        }

        int[][] score = new int[n][];
        st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < n; i++) {
            score[i] = new int[2];
            score[i][0] = Integer.parseInt(st.nextToken());
            score[i][1] = i + 1;
        }
        Arrays.sort(score, (o1, o2) -> o2[0] - o1[0]);

        ArrayList<ArrayList<ArrayList<Integer>>> state = new ArrayList<>();
        {
            ArrayList<ArrayList<Integer>> tmp2 = new ArrayList<>();
            for (int i = 0; i < k; i++) tmp2.add(new ArrayList<>());
            state.add(tmp2);
        }

        for (var ii : score) {
            var i = ii[1];
            HashSet<String> vis = new HashSet<>();
            ArrayList<ArrayList<ArrayList<Integer>>> next = new ArrayList<>();

            for (var before : state) {
                for (int j : vec[i]) {
                    if (before.get(j).size() < x) {
                        ArrayList<ArrayList<Integer>> tmp = new ArrayList<>();
                        for (var a : before) {
                            ArrayList<Integer> t = new ArrayList<>(a);
                            tmp.add(t);
                        }
                        tmp.get(j).add(i);

                        StringBuilder ss = new StringBuilder();
                        for (var a : tmp) ss.append(a.size() < 10 ? "0" + a.size() : a.size());
                        String key = ss.toString();

                        if (vis.contains(key)) continue;

                        vis.add(key);
                        next.add(tmp);
                    }
                }
            }

            if (next.size() > 0) {
                state = next;
            }
        }

        for (var i : state.get(0)) {
            System.out.printf("%d ", i.size());
            for (int j : i) System.out.printf("%d ", j);
            System.out.println();
        }
    }
}
