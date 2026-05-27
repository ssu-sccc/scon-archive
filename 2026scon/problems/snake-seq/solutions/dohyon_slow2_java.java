import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int lowerKey(Pair tmp, ArrayList<Tuple> L) {
        int s = -1, e = L.size(), m;
        while (s + 1 < e) {
            m = (s + e) >> 1;
            if (L.get(m).p.compareTo(tmp) < 0)
                s = m;
            else
                e = m;
        }
        return s;
    }

    static int higherKey(Pair tmp, ArrayList<Tuple> L) {
        int s = -1, e = L.size(), m;
        while (s + 1 < e) {
            m = (s + e) >> 1;
            if (L.get(m).p.compareTo(tmp) > 0)
                e = m;
            else
                s = m;
        }
        return e;
    }

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
        ArrayList<Tuple> T = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            T.add(new Tuple(L.get(i), -1, i));
            for (int j = 0; j < N; j++)
                if (L.get(i).x < L.get(j).x && L.get(i).y < L.get(j).y)
                    T.add(new Tuple(new Pair(L.get(j).x - L.get(i).x, L.get(j).y - L.get(i).y), i, j));
        }
        T.sort(new Comparator<Tuple>() {
            @Override
            public int compare(Tuple o1, Tuple o2) {
                return o1.p.compareTo(o2.p);
            }
        });
        int ans = 1;
        boolean[] visit = new boolean[N];
        ArrayList<Tuple>[] sort = new ArrayList[N];
        for (int i = 0; i < N; i++)
            sort[i] = new ArrayList<>();
        for (Tuple t : T) {
            int j = t.j;
            t.i = t.j = t.i == -1 ? 1 : 0;
            if (!sort[j].isEmpty() && sort[j].get(sort[j].size() - 1).p.compareTo(t.p) == 0) {
                if (t.i == 1)
                    sort[j].get(sort[j].size() - 1).i = sort[j].get(sort[j].size() - 1).j = 1;
            } else
                sort[j].add(t);
        }
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < j; i++)
                if (L.get(i).x < L.get(j).x && L.get(i).y < L.get(j).y) {
                    if (!visit[i]) {
                        visit[i] = true;
                        for (int k = 1; k < sort[i].size(); k++)
                            sort[i].get(k).i = Integer.max(sort[i].get(k).i, sort[i].get(k - 1).i);
                        for (int k = sort[i].size() - 2; k >= 0; k--)
                            sort[i].get(k).j = Integer.max(sort[i].get(k).j, sort[i].get(k + 1).j);
                    }
                    long dx = L.get(j).x - L.get(i).x, dy = L.get(j).y - L.get(i).y;
                    Pair tmp = new Pair(dx, dy);
                    int lo = lowerKey(tmp, sort[i]), hi = higherKey(tmp, sort[i]);
                    int idx = lowerKey(tmp, sort[j]) + 1;
                    if (lo != -1 && sort[i].get(lo).i != 0) {
                        int val = sort[i].get(lo).i + 1;
                        sort[j].get(idx).j = Integer.max(sort[j].get(idx).j, val);
                        ans = Integer.max(ans, val);
                    }
                    if (hi != sort[i].size() && sort[i].get(hi).j != 0) {
                        int val = sort[i].get(hi).j + 1;
                        sort[j].get(idx).i = Integer.max(sort[j].get(idx).i, val);
                        ans = Integer.max(ans, val);
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

class Tuple {
    Pair p;
    int i, j;

    Tuple(Pair p, int i, int j) {
        this.p = p;
        this.i = i;
        this.j = j;
    }
}