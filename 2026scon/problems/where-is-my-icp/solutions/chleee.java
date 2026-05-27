import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();
        int M = sc.nextInt();
        String T = sc.next();
        
        int[] need = new int[26];
        for (char c : "ICPC".toCharArray()) need[c - 'A']++;
        for (char c : S.toCharArray()) need[c - 'A']--;
        for (char c : T.toCharArray()) need[c - 'A']--;
        
        boolean f = true;
        for (int i = 0; i < 26; i++)
            if (need[i] > 0) { f = false; break; }

        System.out.println(f ? "m4us happy" : "m4us sad");
    }
}
