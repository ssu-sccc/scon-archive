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
        ArrayList<Pair> L = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
            L.add(new Pair(x, y));
        }
        L.sort(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.x == o2.x ? Long.compare(o1.y, o2.y) : Long.compare(o1.x, o2.x);
            }
        });
        int ans = 1;
        boolean[] visit = new boolean[N];
        TreeMap<Pair, Integer>[][] T = new TreeMap[2][N];
        for (int i = 0; i < N; i++) {
            T[0][i] = new TreeMap<>();
            T[1][i] = new TreeMap<>();
        }
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < j; i++)
                if (L.get(i).x < L.get(j).x && L.get(i).y < L.get(j).y) {
                    if (!visit[i]) {
                        visit[i] = true;
                        T[0][i].put(L.get(i), Integer.max(T[0][i].getOrDefault(L.get(i), 0), 1));
                        T[1][i].put(L.get(i), Integer.max(T[1][i].getOrDefault(L.get(i), 0), 1));
                        int max = 0;
                        for (Pair p : T[0][i].keySet()) {
                            max = Integer.max(max, T[0][i].get(p));
                            T[0][i].put(p, max);
                        }
                        max = 0;
                        for (Pair p : T[1][i].descendingKeySet()) {
                            max = Integer.max(max, T[1][i].get(p));
                            T[1][i].put(p, max);
                        }
                    }
                    long dx = L.get(j).x - L.get(i).x, dy = L.get(j).y - L.get(i).y;
                    Pair tmp = new Pair(dx, dy);
                    Pair lo = T[0][i].lowerKey(tmp);
                    Pair hi = T[1][i].higherKey(tmp);
                    if (lo != null) {
                        int val = T[0][i].get(lo) + 1;
                        T[1][j].put(tmp, Integer.max(T[1][j].getOrDefault(tmp, 0), val));
                        ans = Integer.max(ans, T[1][j].get(tmp));
                    }
                    if (hi != null) {
                        int val = T[1][i].get(hi) + 1;
                        T[0][j].put(tmp, Integer.max(T[0][j].getOrDefault(tmp, 0), val));
                        ans = Integer.max(ans, T[0][j].get(tmp));
                    }
                }
        }
        System.out.println(ans);
    }
}

class Pair implements Comparable<Pair>{
    long x, y;

    Pair(long x, long y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair o) {
        return Long.compare(this.y * o.x, o.y * this.x);
    }
}
