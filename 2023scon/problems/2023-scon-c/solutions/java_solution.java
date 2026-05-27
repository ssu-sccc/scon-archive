import java.util.*;
import java.io.*;
 
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] a = br.readLine().split(" ");
        for (int i=2; i<n; i++) {
            if (Integer.parseInt(a[i])-Integer.parseInt(a[i-1]) != Integer.parseInt(a[1])-Integer.parseInt(a[0])) {
                System.out.println("NO");
                System.exit(0);
            }
        }
        System.out.println("YES");
        System.out.println(String.join(" ", a));
        System.out.println(String.join(" ", Collections.nCopies(n, "0")));
    }
}