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
        int nS = Integer.parseInt(st.nextToken());
        int nC = Integer.parseInt(st.nextToken());
        int nO = Integer.parseInt(st.nextToken());
        int nN = Integer.parseInt(st.nextToken());
        nS += nN;
        nC += nO * 2;
        System.out.println(Integer.min(nS / 3, nC / 6));
    }
}