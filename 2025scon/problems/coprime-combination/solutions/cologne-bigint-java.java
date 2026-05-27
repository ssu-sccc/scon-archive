import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Precompute factorials up to 5000
        BigInteger[] f = new BigInteger[5001];
        f[0] = BigInteger.ONE;
        for (int i = 1; i <= 5000; i++) {
            f[i] = f[i-1].multiply(BigInteger.valueOf(i));
        }

        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int n1 = sc.nextInt();
            int r1 = sc.nextInt();
            int n2 = sc.nextInt();
            int r2 = sc.nextInt();

            // Calculate combinations
            BigInteger c1 = f[n1].divide(f[r1].multiply(f[n1-r1]));
            BigInteger c2 = f[n2].divide(f[r2].multiply(f[n2-r2]));

            // Check if GCD is 1
            System.out.println(c1.gcd(c2).equals(BigInteger.ONE) ? 1 : 0);
        }
        sc.close();
    }
}